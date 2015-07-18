#ifndef _EXTRACTORC3_HPP_
#define _EXTRACTORC3_HPP_

#include "ExtractorCX.hpp"

// valeur de capacité "Regeneration" d’une unité.
class ExtractorC3 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorC3(Extractor<Unit> * eu) {
        ec_ = new ExtractorCX(eu, ECapacities::Regeneration);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORC3_HPP_