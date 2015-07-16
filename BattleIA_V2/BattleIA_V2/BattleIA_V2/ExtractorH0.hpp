#ifndef _EXTRACTORH0_HPP_
#define _EXTRACTORH0_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus de vitesse
class ExtractorH0 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorH0(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getHigestUnit(ECapacities::Speed);
    }
};

#endif // _EXTRACTORH0_HPP_