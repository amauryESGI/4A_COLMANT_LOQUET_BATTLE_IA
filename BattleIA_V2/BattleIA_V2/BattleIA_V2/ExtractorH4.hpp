#ifndef _EXTRACTORH4_HPP_
#define _EXTRACTORH4_HPP_

#include "ExtractorHX.hpp"

// ennemi qui a le plus de dommage
class ExtractorH4 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorH4(Extractor<Army> * ea) {
        ec_ = new ExtractorHX(ea, ECapacities::Damage);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORH4_HPP_