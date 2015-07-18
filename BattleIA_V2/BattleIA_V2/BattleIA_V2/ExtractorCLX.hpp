#ifndef _EXTRACTORCLX_HPP_
#define _EXTRACTORCLX_HPP_

#include "ExtractorLX.hpp"
#include "ECapacities.hpp"

// valeurs d'une capacité ECapacities

class ExtractorCHX : public Extractor<float> {
private:
    Extractor<Unit> * eu_;
    ECapacities idCapacity_;

public:
    ExtractorCHX(Extractor<Army> * ea, ECapacities idC) : idCapacity_(idC) {
        eu_ = new ExtractorLX(ea, idC);
    }

    float get(Unit u, Army& a, Army& o) const {
        return eu_->get(u, a, o).getCapacity(idCapacity_)->getValue();
    }
};

#endif // _EXTRACTORCLX_HPP_