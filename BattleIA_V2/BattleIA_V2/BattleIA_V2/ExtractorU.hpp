#ifndef _EXTRACTORU_HPP_
#define _EXTRACTORU_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

class ExtractorU : public Extractor<Unit> {
public:
    Unit get(Unit u, Army& a, Army& o) const
    {
        return u;
    }
};

class ExtractorU2 : public Extractor<float> {
public:
    float get(Unit u, Army& a, Army& o) const {
        return 0; // TODO FIX IT
    }
};

#endif // _EXTRACTORU_HPP_