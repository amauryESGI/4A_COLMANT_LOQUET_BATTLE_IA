#ifndef _EXTRACTORLCX_HPP_
#define _EXTRACTORLCX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// valeurs d'une capacité ECapacities

class ExtractorLCX : public Extractor<Unit> {
private:
    Extractor<Army> * ea_;
    ECapacities idCapacity_;

public:
    ExtractorLCX(Extractor<Army> * ea, ECapacities idC) : ea_(ea), idCapacity_(idC) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getLowestUnit(idCapacity_);
    }
};

#endif // _EXTRACTORLCX_HPP_