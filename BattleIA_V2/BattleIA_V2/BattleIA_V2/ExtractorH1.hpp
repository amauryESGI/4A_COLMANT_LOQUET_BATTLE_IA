#ifndef _EXTRACTORH1_HPP_
#define _EXTRACTORH1_HPP_

#include "ExtractorHX.hpp"

// ennemi qui a le plus de point de vie
class ExtractorH1 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorH1(Extractor<Army> * ea) {
        ec_ = new ExtractorHX(ea, ECapacities::HealthPoint);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORH1_HPP_