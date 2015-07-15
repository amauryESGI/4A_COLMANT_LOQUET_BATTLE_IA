#ifndef _EXTRACTORH0_HPP_
#define _EXTRACTORH0_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// ennemi qui a le plus de vitesse
class ExtractorH0 : public Extractor<Unit> {
public:
    ExtractorH0() {}

    Unit get(Unit u, Army& a, Army& o) const {
        return u; // TODO FIX IT
    }
};

#endif _EXTRACTORH0_HPP_