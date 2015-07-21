#ifndef _EXTRACTORO_HPP_
#define _EXTRACTORO_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

class ExtractorO : public Extractor<Army> {
public:
    Army get(Unit u, Army& a, Army& o) const {
        return o;
    }

    std::string getIACode() {
        return std::string("O");
    }
};

#endif // _EXTRACTORO_HPP_