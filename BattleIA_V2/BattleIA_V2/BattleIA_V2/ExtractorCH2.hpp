#ifndef _EXTRACTORC2_HPP_
#define _EXTRACTORC2_HPP_

#include "ExtractorCX.hpp"

// valeur de capacité "Armor" d’une unité.
class ExtractorC2 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorC2(Extractor<Unit> * eu) {
        ec_ = new ExtractorCX(eu, ECapacities::Armor);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORC2_HPP_