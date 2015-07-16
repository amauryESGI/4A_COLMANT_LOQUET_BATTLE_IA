#ifndef _EXTRACTORL4_HPP_
#define _EXTRACTORL4_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le moins de dommage
class ExtractorL4 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorL4(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getLowestUnit(ECapacities::Damage);
    }
};

#endif // _EXTRACTORL4_HPP_