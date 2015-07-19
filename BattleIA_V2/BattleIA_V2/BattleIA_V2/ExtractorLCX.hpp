#ifndef _EXTRACTORLCX_HPP_
#define _EXTRACTORLCX_HPP_

#include "ExtractorLX.hpp"
#include "ECapacities.hpp"

// valeurs d'une capacité ECapacities

class ExtractorLCX : public Extractor<float> {
private:
    Extractor<Unit> * eu_;
    ECapacities idCapacity_;

public:
    ExtractorLCX(Extractor<Army> * ea, ECapacities idC) : idCapacity_(idC) {
        eu_ = new ExtractorLX(ea, idC);
    }

    float get(Unit u, Army& a, Army& o) const {
        return eu_->get(u, a, o).getCapacity(idCapacity_)->getValue();
    }
};

#endif // _EXTRACTORLCX_HPP_