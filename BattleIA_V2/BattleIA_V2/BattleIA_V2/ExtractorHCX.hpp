#ifndef _EXTRACTORHCX_HPP_
#define _EXTRACTORHCX_HPP_

#include "ExtractorHX.hpp"
#include "ECapacities.hpp"

// valeurs d'une capacité ECapacities

class ExtractorHCX : public Extractor<float> {
private:
    Extractor<Unit> * eu_;
    ECapacities idCapacity_;

public:
    ExtractorHCX(Extractor<Army> * ea, ECapacities idC) : idCapacity_(idC) {
        eu_ = new ExtractorHX(ea, idC);
    }

    float get(Unit u, Army& a, Army& o) const {
        return eu_->get(u, a, o).getCapacity(idCapacity_)->getValue();
    }
};

#endif // _EXTRACTORHCX_HPP_