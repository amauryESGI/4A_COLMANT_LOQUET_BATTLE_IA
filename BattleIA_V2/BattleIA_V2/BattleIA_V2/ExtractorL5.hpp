#ifndef _EXTRACTORL5_HPP_
#define _EXTRACTORL5_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "ECapacities.hpp"

// ennemi qui a le moins de portée
class ExtractorL5 : public Extractor<Unit> {
private:
    Extractor<Army> * eo_;

public:
    ExtractorL5(Extractor<Army> * eo) : eo_(eo) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return eo_->get(u, a, o).getLowestUnit(ECapacities::Scope);
    }
};

#endif // _EXTRACTORL5_HPP_