#ifndef _EXTRACTORL1_HPP_
#define _EXTRACTORL1_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le moins de point de vie
class ExtractorL1 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorL1(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getLowestUnit(ECapacities::HealthPoint);
    }
};

#endif // _EXTRACTORL1_HPP_