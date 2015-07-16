#ifndef _EXTRACTORH1_HPP_
#define _EXTRACTORH1_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus de point de vie
class ExtractorH1 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorH1(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getHigestUnit(ECapacities::HealthPoint);
    }
};

#endif // _EXTRACTORH1_HPP_