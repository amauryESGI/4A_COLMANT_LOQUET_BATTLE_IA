#include "Build.hpp"

#include "Extractor.hpp"

#include "ExtractorP.hpp"
#include "ExtractorU.hpp"
#include "ExtractorA.hpp"
#include "ExtractorO.hpp"
#include "ExtractorB.hpp"
#include "ExtractorDirect.hpp"

#include "ExtractorCX.hpp"
#include "ExtractorLCX.hpp"
#include "ExtractorHCX.hpp"
#include "ExtractorMinCX.hpp"
#include "ExtractorMaxCX.hpp"
#include "ExtractorMoyCX.hpp"
#include "ExtractorNLX.hpp"
#include "ExtractorNHX.hpp"
#include "ExtractorTLX.hpp"
#include "ExtractorTHX.hpp"

#include "ExtractorD.hpp"
#include "ExtractorLD.hpp"
#include "ExtractorHD.hpp"
#include "ExtractorMinD.hpp"
#include "ExtractorMaxD.hpp"
#include "ExtractorMoyD.hpp"
#include "ExtractorNLD.hpp"
#include "ExtractorNHD.hpp"

#include "Action.hpp"
#include "EmptyAction.hpp"
#include "MoveAction.hpp"
#include "ShotAction.hpp"
#include "FleeAction.hpp"

#include "OperatorInf.hpp"
#include "OperatorSup.hpp"


Build::Build() {
}


Build::~Build() {
}

Extractor<int>* Build::buildIntExtractor(std::stringstream* code) {
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

Extractor<float>* Build::buildFloatExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case 'C':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorCX(buildUnitExtractor(code), (ECapacities) (c - 0x30));
    case 'D':
        return new ExtractorD(buildUnitExtractor(code), buildPointExtractor(code));
    case 'M':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMaxCX(buildArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army> * ea = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorMaxD(ea, ep);
        }
    case 'm':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMinCX(buildArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorMinD(es, ep);
        }
    case 'a':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMoyCX(buildArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorMoyD(es, ep);
        }
    }
}

Extractor<Point>* Build::buildPointExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case 'B':
        return new ExtractorB(buildArmyExtractor(code));
    case 'P':
        return new ExtractorP(buildUnitExtractor(code));
    }
}

Extractor<Unit>* Build::buildUnitExtractor(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case 'U':
        return new ExtractorU();
    case 'L':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorLCX(buildArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorLD(es, ep);
        }
    case 'H':
        *code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorHCX(buildArmyExtractor(code), (ECapacities) (c - 0x30));
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorHD(es, ep);
        }
    }
}

Extractor<Army>* Build::buildArmyExtractor(std::stringstream* code) {
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
                Extractor<int> * ei = buildIntExtractor(code);
                Extractor<Army>* es = buildArmyExtractor(code);
                Extractor<Point>* ep = buildPointExtractor(code);
                return new ExtractorNLD(ei, es, ep);
            } else {
                Extractor<int> * ei = buildIntExtractor(code);
                Extractor<Army>* es = buildArmyExtractor(code);
                return new ExtractorNLX(ei, es, c - 0x30);
            }
        } else {
            *code >> c;
            if (c == 'D') {
                Extractor<int> * ei = buildIntExtractor(code);
                Extractor<Army>* es = buildArmyExtractor(code);
                Extractor<Point>* ep = buildPointExtractor(code);
                return new ExtractorNHD(ei, es, ep);
            } else {
                Extractor<int> * ei = buildIntExtractor(code);
                Extractor<Army>* es = buildArmyExtractor(code);
                return new ExtractorNHX(ei, es, c - 0x30);
            }
        }
        break;
    case 'T':
        *code >> c;
        if (c == 'L') {
            Extractor<int> * ei = buildIntExtractor(code);
            Extractor<Army>* es = buildArmyExtractor(code);
            return new ExtractorTLX(ei, es, c - 0x30);
        } else {
            Extractor<int> * ei = buildIntExtractor(code);
            Extractor<Army>* es = buildArmyExtractor(code);
            return new ExtractorTHX(ei, es, c - 0x30);
        }
        break;
    }
}
InternalNode * Build::buildInternalNode(std::stringstream* code) {
    Extractor<float> * leftSide = buildFloatExtractor(code);
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
    Extractor<float> * rightSide = buildFloatExtractor(code);
    Node * l_son = buildTree(code);
    Node * r_son = buildTree(code);
    return new InternalNode(cmp, l_son, r_son, leftSide, rightSide);
}

Node * Build::buildLeaf(std::stringstream* code) {
    Node * action = nullptr;
    char c;
    *code >> c;
    switch (c) {
    case 'M':
    {
        Extractor<Point> * ep = buildPointExtractor(code);
        action = new LeafMove(ep);
        break;
    }
    case 'E':
    {
        Extractor<Point> * ep = buildPointExtractor(code);
        action = new LeafFlee(ep);
        break;
    }
    case 'A':
    {
        Extractor<Unit> * eu = buildUnitExtractor(code);
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

Node * Build::buildTree(std::stringstream* code) {
    char c;
    *code >> c;
    switch (c) {
    case '?':
        return buildInternalNode(code);
    case '!':
        return buildLeaf(code);
    }
}