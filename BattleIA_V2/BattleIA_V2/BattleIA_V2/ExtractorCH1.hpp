#ifndef _EXTRACTORC1_HPP_
#define _EXTRACTORC1_HPP_

#include "ExtractorCX.hpp"

// valeur de capacité "HealthPoint" d’une unité.
class ExtractorC1 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorC1(Extractor<Unit> * eu) {
        ec_ = new ExtractorCX(eu, ECapacities::HealthPoint);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORC1_HPP_