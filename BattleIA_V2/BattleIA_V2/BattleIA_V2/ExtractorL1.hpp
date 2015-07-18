#ifndef _EXTRACTORL1_HPP_
#define _EXTRACTORL1_HPP_

#include "ExtractorLX.hpp"

// ennemi qui a le moins de point de vie
class ExtractorL1 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorL1(Extractor<Army> * ea) {
        ec_ = new ExtractorLX(ea, ECapacities::HealthPoint);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORL1_HPP_