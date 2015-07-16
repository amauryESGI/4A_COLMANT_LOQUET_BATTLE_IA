#ifndef _EXTRACTORL0_HPP_
#define _EXTRACTORL0_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le moins de vitesse
class ExtractorL0 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorL0(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getLowestUnit(ECapacities::Speed);
    }
};

#endif _EXTRACTORL0_HPP_