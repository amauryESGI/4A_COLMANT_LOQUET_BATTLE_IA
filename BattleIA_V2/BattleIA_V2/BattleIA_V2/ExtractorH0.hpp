#ifndef _EXTRACTORH0_HPP_
#define _EXTRACTORH0_HPP_

#include "ExtractorHX.hpp"

// ennemi qui a le plus de vitesse
class ExtractorH0 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorH0(Extractor<Army> * ea) {
        ec_ = new ExtractorHX(ea, ECapacities::Speed);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORH0_HPP_