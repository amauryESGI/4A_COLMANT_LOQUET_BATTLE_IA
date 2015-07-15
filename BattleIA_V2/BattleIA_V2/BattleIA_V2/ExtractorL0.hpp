#ifndef _EXTRACTORL0_HPP_
#define _EXTRACTORL0_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// ennemi qui a le plus de vitesse
class ExtractorL0 : public Extractor<Unit> {
public:
    ExtractorL0() {}

    Unit get(Unit u, Army& a, Army& o) const {
        return u; // TODO FIX IT
    }
};

#endif _EXTRACTORL0_HPP_