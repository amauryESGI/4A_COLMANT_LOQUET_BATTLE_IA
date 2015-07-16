#ifndef _EXTRACTORH5_HPP_
#define _EXTRACTORH5_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus de portée
class ExtractorH5 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorH5(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getHigestUnit(ECapacities::Scope);
    }
};

#endif // _EXTRACTORH5_HPP_