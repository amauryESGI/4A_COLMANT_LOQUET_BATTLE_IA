#ifndef _EXTRACTORC5_HPP_
#define _EXTRACTORC5_HPP_

#include "ExtractorCX.hpp"

// valeur de capacité "Scope" d’une unité.
class ExtractorC5 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorC5(Extractor<Unit> * eu) {
        ec_ = new ExtractorCX(eu, ECapacities::Scope);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORC5_HPP_