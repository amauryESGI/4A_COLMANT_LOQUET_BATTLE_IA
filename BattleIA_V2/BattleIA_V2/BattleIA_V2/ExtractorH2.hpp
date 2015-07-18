#ifndef _EXTRACTORH2_HPP_
#define _EXTRACTORH2_HPP_

#include "ExtractorHX.hpp"

// ennemi qui a le plus de point d'armure
class ExtractorH2 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorH2(Extractor<Army> * ea) {
        ec_ = new ExtractorHX(ea, ECapacities::Armor);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORH0_HPP_