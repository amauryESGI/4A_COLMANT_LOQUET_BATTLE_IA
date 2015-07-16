#ifndef _EXTRACTORH6_HPP_
#define _EXTRACTORH6_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus de cooldown
class ExtractorH6 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorH6(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getHigestUnit(ECapacities::WeaponSpeed);
    }
};

#endif // _EXTRACTORH6_HPP_