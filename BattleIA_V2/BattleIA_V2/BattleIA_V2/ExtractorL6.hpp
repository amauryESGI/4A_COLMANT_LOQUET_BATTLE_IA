#ifndef _EXTRACTORL6_HPP_
#define _EXTRACTORL6_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le moins de cooldown
class ExtractorL6 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorL6(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getLowestUnit(ECapacities::WeaponSpeed);
    }
};

#endif // _EXTRACTORL6_HPP_