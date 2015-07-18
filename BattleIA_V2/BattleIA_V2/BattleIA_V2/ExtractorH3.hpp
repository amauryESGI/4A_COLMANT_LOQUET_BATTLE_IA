#ifndef _EXTRACTORH3_HPP_
#define _EXTRACTORH3_HPP_

#include "ExtractorHX.hpp"

// ennemi qui a le plus de point de vie regeneré par tour
class ExtractorH3 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorH3(Extractor<Army> * ea) {
        ec_ = new ExtractorHX(ea, ECapacities::Regeneration);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORH3_HPP_