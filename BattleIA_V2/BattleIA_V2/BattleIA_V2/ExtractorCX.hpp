#ifndef _EXTRACTORCX_HPP_
#define _EXTRACTORCX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// valeurs d'une capacité ECapacities

class ExtractorCX : public Extractor<float> {
private:
    Extractor<Unit&> * eu_;
    ECapacities idCapacity_;

public:
    ExtractorCX(Extractor<Unit&> * eu, ECapacities idC) : eu_(eu), idCapacity_(idC) {}

    float get(Unit& u, Army& a, Army& o) const {
        return eu_->get(u, a, o).getCapacity(idCapacity_)->getValue();
    }

    std::string getIACode() {
        return std::string("C") + std::to_string(idCapacity_) + eu_->getIACode();
    }
};

#endif // _EXTRACTORHCX_HPP_