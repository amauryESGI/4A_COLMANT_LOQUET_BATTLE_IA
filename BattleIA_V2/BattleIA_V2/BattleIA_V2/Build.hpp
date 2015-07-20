#ifndef _BUILD_HPP_
#define _BUILD_HPP_

#include <sstream>
#include "Extractor.hpp"
#include "InternalNode.hpp"
#include "Leaf.hpp"

class Build {
private:
    Extractor<int>*     buildIntExtractor(std::stringstream* code);
    Extractor<float>*   buildFloatExtractor(std::stringstream* code);
    Extractor<Point>*   buildPointExtractor(std::stringstream* code);
    Extractor<Unit>*    buildUnitExtractor(std::stringstream* code);
    Extractor<Army>*    buildArmyExtractor(std::stringstream* code);

    InternalNode*       buildInternalNode(std::stringstream* code);
    Leaf*               buildLeaf(std::stringstream* code);
    Node*               buildTree(std::stringstream* code);

public:
    Build();
    ~Build();
};

#endif // _BUILD_HPP_