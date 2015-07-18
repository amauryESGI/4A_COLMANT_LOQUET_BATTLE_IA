#ifndef _EXTRACTORC4_HPP_
#define _EXTRACTORC4_HPP_

#include "ExtractorCX.hpp"

// valeur de capacité "Damage" d’une unité.
class ExtractorC4 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorC4(Extractor<Unit> * eu) {
        ec_ = new ExtractorCX(eu, ECapacities::Damage);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORC4_HPP_