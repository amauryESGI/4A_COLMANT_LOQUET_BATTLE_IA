#ifndef _BUILD_HPP_
#define _BUILD_HPP_

#include <sstream>
#include "Extractor.hpp"
#include "InternalNode.hpp"

class Build {
private:
    static Extractor<int>*     Creat_IntExtractor(std::stringstream* code);
    static Extractor<float>*   Creat_FloatExtractor(std::stringstream* code);
    static Extractor<Point>*   Creat_PointExtractor(std::stringstream* code);
    static Extractor<Unit>*    Creat_UnitExtractor(std::stringstream* code);
    static Extractor<Army>*    Creat_ArmyExtractor(std::stringstream* code);

    static InternalNode*       Creat_InternalNode(std::stringstream* code);
    static Node*               Creat_Leaf(std::stringstream* code);
    static Node*               Creat_Tree(std::stringstream* code);

public:
    Build();
    ~Build();
    static Node* BuildTree(std::string* str);
};

#endif // _BUILD_HPP_