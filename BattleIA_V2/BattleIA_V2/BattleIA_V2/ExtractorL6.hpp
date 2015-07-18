#ifndef _EXTRACTORL6_HPP_
#define _EXTRACTORL6_HPP_

#include "ExtractorLX.hpp"

// ennemi qui a le moins de cooldown
class ExtractorL6 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorL6(Extractor<Army> * ea) {
        ec_ = new ExtractorLX(ea, ECapacities::WeaponSpeed);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORL6_HPP_