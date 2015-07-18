#ifndef _EXTRACTORL0_HPP_
#define _EXTRACTORL0_HPP_

#include "ExtractorLX.hpp"

// ennemi qui a le moins de vitesse
class ExtractorL0 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorL0(Extractor<Army> * ea) {
        ec_ = new ExtractorLX(ea, ECapacities::Speed);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORL0_HPP_