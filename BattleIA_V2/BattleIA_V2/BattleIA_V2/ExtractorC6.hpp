#ifndef _EXTRACTORC6_HPP_
#define _EXTRACTORC6_HPP_

#include "ExtractorCX.hpp"

// valeur de capacité "WeaponSpeed" d’une unité.
class ExtractorC6 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorC6(Extractor<Unit> * eu) {
        ec_ = new ExtractorCX(eu, ECapacities::WeaponSpeed);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORC6_HPP_