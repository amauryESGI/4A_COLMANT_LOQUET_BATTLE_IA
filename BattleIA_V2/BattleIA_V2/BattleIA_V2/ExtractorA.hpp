#ifndef _EXTRACTORA_HPP_
#define _EXTRACTORA_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

class ExtractorA : public Extractor<Army> {
public:
    Army get(Unit u, Army& a, Army& o) const
    {
        return a;
    }
};

#endif // _EXTRACTORA_HPP_