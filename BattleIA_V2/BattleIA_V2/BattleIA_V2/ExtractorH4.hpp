#ifndef _EXTRACTORH4_HPP_
#define _EXTRACTORH4_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus de dommage
class ExtractorH4 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorH4(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getHigestUnit(ECapacities::Damage);
    }
};

#endif // _EXTRACTORH4_HPP_