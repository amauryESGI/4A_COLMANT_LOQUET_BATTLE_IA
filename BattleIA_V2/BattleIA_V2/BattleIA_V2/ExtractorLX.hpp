#ifndef _EXTRACTORLX_HPP_
#define _EXTRACTORLX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus haut dans une capacité ECapacities
class ExtractorLX : public Extractor<Unit> {
private:
    Extractor<Army> * ea_;
    ECapacities idCapacity_;

public:
    ExtractorLX(Extractor<Army> * ea, ECapacities idC) : ea_(ea), idCapacity_(idC) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getLowestUnit(idCapacity_);
    }
};

#endif // _EXTRACTORLX_HPP_