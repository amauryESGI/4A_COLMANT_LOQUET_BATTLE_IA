#ifndef _EXTRACTORCHX_HPP_
#define _EXTRACTORCHX_HPP_

#include "ExtractorHX.hpp"
#include "ECapacities.hpp"

// valeurs d'une capacité ECapacities

class ExtractorCHX : public Extractor<float> {
private:
    Extractor<Unit> * eu_;
    ECapacities idCapacity_;

public:
    ExtractorCHX(Extractor<Army> * ea, ECapacities idC) : idCapacity_(idC) {
        eu_ = new ExtractorHX(ea, idC);
    }

    float get(Unit u, Army& a, Army& o) const {
        return eu_->get(u, a, o).getCapacity(idCapacity_)->getValue();
    }
};

#endif // _EXTRACTORCHX_HPP_