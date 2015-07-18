#ifndef _EXTRACTORH5_HPP_
#define _EXTRACTORH5_HPP_

#include "ExtractorHX.hpp"

// ennemi qui a le plus de portée
class ExtractorH5 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorH5(Extractor<Army> * ea) {
        ec_ = new ExtractorHX(ea, ECapacities::Scope);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORH5_HPP_