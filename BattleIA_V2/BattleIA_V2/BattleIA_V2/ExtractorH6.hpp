#ifndef _EXTRACTORH6_HPP_
#define _EXTRACTORH6_HPP_

#include "ExtractorHX.hpp"

// ennemi qui a le plus de cooldown
class ExtractorH6 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorH6(Extractor<Army> * ea) {
        ec_ = new ExtractorHX(ea, ECapacities::WeaponSpeed);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORH6_HPP_