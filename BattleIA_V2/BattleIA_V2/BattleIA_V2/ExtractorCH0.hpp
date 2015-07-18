#ifndef _EXTRACTORCH0_HPP_
#define _EXTRACTORCH0_HPP_

#include "ExtractorCHX.hpp"

// valeur de capacité "Speed" d’une unité.
class ExtractorCH0 : public Extractor<float> {
private:
    Extractor<float> * ec_;

public:
    ExtractorCH0(Extractor<Army> * ea) {
        ec_ = new ExtractorCHX(ea, ECapacities::Speed);
    }

    float get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORCH0_HPP_