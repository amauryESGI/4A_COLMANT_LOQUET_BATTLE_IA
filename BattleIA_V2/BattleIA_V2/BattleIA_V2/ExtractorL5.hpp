#ifndef _EXTRACTORL5_HPP_
#define _EXTRACTORL5_HPP_

#include "ExtractorLX.hpp"

// ennemi qui a le moins de portée
class ExtractorL5 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorL5(Extractor<Army> * ea) {
        ec_ = new ExtractorLX(ea, ECapacities::Scope);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORL5_HPP_