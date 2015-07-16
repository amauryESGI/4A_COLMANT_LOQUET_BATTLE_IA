#ifndef _EXTRACTORL2_HPP_
#define _EXTRACTORL2_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le moins de point d'armure
class ExtractorL2 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorL2(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getLowestUnit(ECapacities::Armor);
    }
};

#endif // _EXTRACTORL2_HPP_