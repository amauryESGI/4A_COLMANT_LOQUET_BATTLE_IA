#ifndef _EXTRACTORC0_HPP_
#define _EXTRACTORC0_HPP_

#include "ExtractorCX.hpp"

// valeur de capacité "vitesse" d’une unité.
class ExtractorC0 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorC0(Extractor<Unit> * eu) {
        ec_ = new ExtractorCX(eu, ECapacities::Speed);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORC0_HPP_