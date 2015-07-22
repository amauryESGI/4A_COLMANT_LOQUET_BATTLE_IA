#ifndef _BUILD_HPP_
#define _BUILD_HPP_

#include <sstream>
#include "Extractor.hpp"
#include "InternalNode.hpp"

class Build {
private:
    static Extractor<int>*     Creat_IntExtractor(std::stringstream* code);
    static Extractor<float>*   Creat_FloatExtractor(std::stringstream* code);
    static Extractor<Point&>*   Creat_PointExtractor(std::stringstream* code);
    static Extractor<Unit&>*    Creat_UnitExtractor(std::stringstream* code);
    static Extractor<Army&>*    Creat_ArmyExtractor(std::stringstream* code);

    static InternalNode*       Creat_InternalNode(std::stringstream* code);
    static Node*               Creat_Leaf(std::stringstream* code);
    static Node*               Creat_Tree(std::stringstream* code);


    static std::string Creat_IntIACode();
    static std::string Creat_FloatIACode();
    static std::string Creat_PointIACode();
    static std::string Creat_UnitIACode();
    static std::string Creat_ArmyIACode();

    static std::string Creat_InternalNodeIACode(int height);
    static std::string Creat_LeafIACode();
    static std::string Creat_TreeIACode(int height);

public:
    Build();
    ~Build();
    static Node* BuildTree(std::string* str);
    static std::string BuildIACode();
};

#endif // _BUILD_HPP_