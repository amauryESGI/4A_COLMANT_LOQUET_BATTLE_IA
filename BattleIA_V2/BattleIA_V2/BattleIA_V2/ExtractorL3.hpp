#ifndef _EXTRACTORL3_HPP_
#define _EXTRACTORL3_HPP_

#include "ExtractorLX.hpp"

// ennemi qui a le moins de point de vie regeneré par tour
class ExtractorL3 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorL3(Extractor<Army> * ea) {
        ec_ = new ExtractorLX(ea, ECapacities::Regeneration);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORL3_HPP_