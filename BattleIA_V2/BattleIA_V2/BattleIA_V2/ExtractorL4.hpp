#ifndef _EXTRACTORL4_HPP_
#define _EXTRACTORL4_HPP_

#include "ExtractorLX.hpp"

// ennemi qui a le moins de dommage
class ExtractorL4 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorL4(Extractor<Army> * ea) {
        ec_ = new ExtractorLX(ea, ECapacities::Damage);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORL4_HPP_