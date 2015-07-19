#ifndef _BUILD_HPP_
#define _BUILD_HPP_

#include <sstream>
#include "Extractor.hpp"

class Build {
private:
    Extractor<int>*     buildIntExtractor(std::stringstream* code);
    Extractor<float>*   buildFloatExtractor(std::stringstream* code);
    Extractor<Point>*   buildPointExtractor(std::stringstream* code);
    Extractor<Unit>*    buildUnitExtractor(std::stringstream* code);
    Extractor<Army>*    buildArmyExtractor(std::stringstream* code);

public:
    Build();
    ~Build();
};

#endif // _BUILD_HPP_