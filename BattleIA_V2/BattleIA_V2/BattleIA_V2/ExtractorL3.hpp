#ifndef _EXTRACTORL3_HPP_
#define _EXTRACTORL3_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le moins de point de vie regeneré par tour
class ExtractorL3 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorL3(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getLowestUnit(ECapacities::Regeneration);
    }
};

#endif // _EXTRACTORL3_HPP_