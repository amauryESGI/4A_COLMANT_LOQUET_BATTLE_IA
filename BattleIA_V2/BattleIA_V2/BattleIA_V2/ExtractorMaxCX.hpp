#ifndef _EXTRACTORMINCX_HPP_
#define _EXTRACTORMINCX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus haut dans une capacité ECapacities
class ExtractorMaxCX : public Extractor<float> {
private:
    ECapacities idCapacity_;
    Extractor<Army> * ea_;

public:
    ExtractorMaxCX(Extractor<Army> * ea, ECapacities idCapacity) : ea_(ea), idCapacity_(idCapacity) {}

    float get(Unit u, Army& a, Army& o) const {
        Army a2 = ea_->get(u, a, o);

        // Distance Max
        float max = 0;

        for (auto &unit : a2.getUnitsList()) {
            float tmp = unit->getCapacity(idCapacity_)->getValue();
            if (tmp > max)
                max = tmp;
        }

        return max;
    }
};

#endif // _EXTRACTORMINCX_HPP_