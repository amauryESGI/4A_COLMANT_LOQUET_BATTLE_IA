#ifndef _EXTRACTORH3_HPP_
#define _EXTRACTORH3_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus de point de vie regeneré par tour
class ExtractorH3 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorH3(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getHigestUnit(ECapacities::Regeneration);
    }
};

#endif // _EXTRACTORH3_HPP_