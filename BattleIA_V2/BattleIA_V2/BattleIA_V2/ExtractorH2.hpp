#ifndef _EXTRACTORH2_HPP_
#define _EXTRACTORH2_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus de point d'armure
class ExtractorH2 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorH2(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getHigestUnit(ECapacities::Armor);
    }
};

#endif // _EXTRACTORH0_HPP_