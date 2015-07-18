#ifndef _EXTRACTORL2_HPP_
#define _EXTRACTORL2_HPP_

#include "ExtractorLX.hpp"

// ennemi qui a le moins de point d'armure
class ExtractorL2 : public Extractor<Unit> {
private:
    Extractor<Unit> * ec_;

public:
    ExtractorL2(Extractor<Army> * ea) {
        ec_ = new ExtractorLX(ea, ECapacities::Armor);
    }

    Unit get(Unit u, Army& a, Army& o) const {
        return ec_->get(u, a, o);
    }
};

#endif // _EXTRACTORL2_HPP_