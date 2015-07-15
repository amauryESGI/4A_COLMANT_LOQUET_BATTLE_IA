#ifndef _EXTRACTORHD_HPP_
#define _EXTRACTORHD_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// ennemi qui a le plus de vitesse
class ExtractorHD : public Extractor<Unit> {
public:
    ExtractorHD() {}

    Unit get(Unit u, Army& a, Army& o) const {
        return u; // TODO FIX IT
    }
};

#endif _EXTRACTORHD_HPP_