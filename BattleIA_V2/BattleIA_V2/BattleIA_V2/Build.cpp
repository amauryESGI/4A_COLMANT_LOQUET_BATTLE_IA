#include "stdafx.h"


Build::Build() {
}

Build::~Build() {
}

Extractor<int>* Build::Creat_IntExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    if (c == '[') {
        std::string s = "";
        *code >> c;
        while (c != ']') {
            s += c;
            *code >> c;
        }
        return new ExtractorDirect(atoi(s.c_str()));
    }
}

Extractor<float>* Build::Creat_FloatExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case 'C':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorCX(Creat_UnitExtractor(code), (ECapacities) (c - 0x30));
    case 'D':
        return new ExtractorD(Creat_UnitExtractor(code), Creat_PointExtractor(code));
    case 'M':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMaxCX(Creat_ArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army&> * ea = Creat_ArmyExtractor(code);
            Extractor<Point&> * ep = Creat_PointExtractor(code);

            return new ExtractorMaxD(ea, ep);
        }
    case 'm':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMinCX(Creat_ArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army&> * es = Creat_ArmyExtractor(code);
            Extractor<Point&> * ep = Creat_PointExtractor(code);

            return new ExtractorMinD(es, ep);
        }
    case 'a':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMoyCX(Creat_ArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army&> * es = Creat_ArmyExtractor(code);
            Extractor<Point&> * ep = Creat_PointExtractor(code);

            return new ExtractorMoyD(es, ep);
        }
    }
}

Extractor<Point&>* Build::Creat_PointExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case 'B':
        return new ExtractorB(Creat_ArmyExtractor(code));
    case 'P':
        return new ExtractorP(Creat_UnitExtractor(code));
    }
}

Extractor<Unit&>* Build::Creat_UnitExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case 'U':
        return new ExtractorU();
    case 'L':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorLCX(Creat_ArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army&> * es = Creat_ArmyExtractor(code);
            Extractor<Point&> * ep = Creat_PointExtractor(code);

            return new ExtractorLD(es, ep);
        }
    case 'H':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorHCX(Creat_ArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army&> * es = Creat_ArmyExtractor(code);
            Extractor<Point&> * ep = Creat_PointExtractor(code);

            return new ExtractorHD(es, ep);
        }
    }
}

Extractor<Army&>* Build::Creat_ArmyExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case 'A':
        return new ExtractorA();
    case 'O':
        return new ExtractorO();
    case 'N':
        *code >> c;
        if (c == 'L') {
            *code >> c;
            if (c == 'D') {
                Extractor<int> * ei = Creat_IntExtractor(code);
                Extractor<Army&>* es = Creat_ArmyExtractor(code);
                Extractor<Point&>* ep = Creat_PointExtractor(code);
                return new ExtractorNLD(ei, es, ep);
            } else {
                Extractor<int> * ei = Creat_IntExtractor(code);
                Extractor<Army&>* es = Creat_ArmyExtractor(code);
                return new ExtractorNLX(ei, es, c - 0x30);
            }
        } else {
            *code >> c;
            if (c == 'D') {
                Extractor<int> * ei = Creat_IntExtractor(code);
                Extractor<Army&>* es = Creat_ArmyExtractor(code);
                Extractor<Point&>* ep = Creat_PointExtractor(code);
                return new ExtractorNHD(ei, es, ep);
            } else {
                Extractor<int> * ei = Creat_IntExtractor(code);
                Extractor<Army&>* es = Creat_ArmyExtractor(code);
                return new ExtractorNHX(ei, es, c - 0x30);
            }
        }
        break;
    case 'T':
        *code >> c;
        if (c == 'L') {
            Extractor<int> * ei = Creat_IntExtractor(code);
            Extractor<Army&>* es = Creat_ArmyExtractor(code);
            return new ExtractorTLX(ei, es, c - 0x30);
        } else {
            Extractor<int> * ei = Creat_IntExtractor(code);
            Extractor<Army&>* es = Creat_ArmyExtractor(code);
            return new ExtractorTHX(ei, es, c - 0x30);
        }
        break;
    }
}

InternalNode * Build::Creat_InternalNode(std::stringstream* code) {
    Extractor<float> * leftSide = Creat_FloatExtractor(code);
    Operator * cmp = nullptr;
    char c;
    *code >> c;
    switch (c) {
    case '<':
        cmp = new OperatorInf();
        break;
    case '>':
        cmp = new OperatorSup();
        break;
    }
    Extractor<float> * rightSide = Creat_FloatExtractor(code);
    Node * l_son = Creat_Tree(code);
    Node * r_son = Creat_Tree(code);
    return new InternalNode(cmp, l_son, r_son, leftSide, rightSide);
}

Node * Build::Creat_Leaf(std::stringstream* code) {
    Node * action = nullptr;
    char c;
    *code >> c;
    switch (c) {
    case 'M':
    {
        Extractor<Point&> * ep = Creat_PointExtractor(code);
        action = new LeafMove(ep);
        break;
    }
    case 'E':
    {
        Extractor<Point&> * ep = Creat_PointExtractor(code);
        action = new LeafFlee(ep);
        break;
    }
    case 'A':
    {
        Extractor<Unit&> * eu = Creat_UnitExtractor(code);
        action = new LeafShot(eu);
        break;
    }
    case 'N':
    {
        action = new LeafEmpty();
        break;
    }
    }

    return action;
}

Node * Build::Creat_Tree(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case '?':
        return Creat_InternalNode(code);
    case '!':
        return Creat_Leaf(code);
    }
}

Node* Build::BuildTree(std::string* str) {
    return Creat_Tree(new std::stringstream(*str));
}

std::string Build::Creat_IntIACode() {
    return "[" + std::to_string(std::rand() % 100) + "]"; // TODO FIX IT
}

std::string Build::Creat_FloatIACode() {
    switch (std::rand() % 5) {
    case 0:
        return "C" + std::to_string(std::rand() % 7) + Creat_UnitIACode();
    case 1:
        return "D" + Creat_UnitIACode() + Creat_PointIACode();
    case 2:
        return (std::rand() % 2) == 0
            ? "M" + std::to_string(std::rand() % 7) + Creat_ArmyIACode()
            : "MD" + Creat_ArmyIACode() + Creat_PointIACode();
    case 3:
        return (std::rand() % 2) == 0
            ? "m" + std::to_string(std::rand() % 7) + Creat_ArmyIACode()
            : "mD" + Creat_ArmyIACode() + Creat_PointIACode();
    case 4:
        return (std::rand() % 2) == 0
            ? "a" + std::to_string(std::rand() % 7) + Creat_ArmyIACode()
            : "aD" + Creat_ArmyIACode() + Creat_PointIACode();
    }
}

std::string Build::Creat_PointIACode() {
    return (std::rand() % 2) == 0
        ? "B" + Creat_ArmyIACode()
        : "P" + Creat_UnitIACode();
}

std::string Build::Creat_UnitIACode() {
    switch (std::rand() % 3) {
    case 0:
        return "U";
    case 1:
        return (std::rand() % 2) == 0
            ? "L" + std::to_string(std::rand() % 7) + Creat_ArmyIACode()
            : "LD" + Creat_ArmyIACode() + Creat_PointIACode();
    case 2:
        return (std::rand() % 2) == 0
            ? "H" + std::to_string(std::rand() % 7) + Creat_ArmyIACode()
            : "HD" + Creat_ArmyIACode() + Creat_PointIACode();
    }
}

std::string Build::Creat_ArmyIACode() {
    switch (std::rand() % 4) {
    case 0:
        return "A";
    case 1:
        return "O";
    case 2:
        if (std::rand() % 2 == 0) {
            return (std::rand() % 2) == 0
                ? "NLD" + Creat_IntIACode() + Creat_ArmyIACode() + Creat_PointIACode()
                : "NL" + std::to_string(std::rand() % 7) + Creat_IntIACode() + Creat_ArmyIACode();
        } else {
            return (std::rand() % 2) == 0
                ? "NHD" + Creat_IntIACode() + Creat_ArmyIACode() + Creat_PointIACode()
                : "NH" + std::to_string(std::rand() % 7) + Creat_IntIACode() + Creat_ArmyIACode();
        }
    case 3:
        return (std::rand() % 2) == 0
            ? "TL" + std::to_string(std::rand() % 7) + Creat_IntIACode() + Creat_ArmyIACode()
            : "TH" + std::to_string(std::rand() % 7) + Creat_IntIACode() + Creat_ArmyIACode();
    }
}

std::string Build::Creat_InternalNodeIACode(int height) {
    std::string cmp = std::rand() % 2 ? "<" : ">";
    return Creat_FloatIACode() + cmp + Creat_FloatIACode() + Creat_TreeIACode(height--) + Creat_TreeIACode(height--);
}

std::string Build::Creat_LeafIACode() {
    switch (std::rand()%4) {
    case 0:
        return "M" + Creat_PointIACode();
    case 1:
        return "E" + Creat_PointIACode();
    case 2:
        return "A" + Creat_UnitIACode();
    case 3:
        return "N";
    }
}

std::string Build::Creat_TreeIACode(int height) {
    if (height <= 0)
        return "!" + Creat_LeafIACode();

    switch (std::rand()%2) {
    case 0:
        return "?" + Creat_InternalNodeIACode(height);
    case 1:
        return "!" + Creat_LeafIACode();
    }
}

std::string Build::BuildIACode() {
    int height = std::rand() % 3;
    return Creat_TreeIACode(height--);
}