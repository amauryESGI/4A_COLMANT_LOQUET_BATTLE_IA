#ifndef _EXTRACTORMAXCX_HPP_
#define _EXTRACTORMAXCX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus haut dans une capacit� ECapacities
class ExtractorMinCX : public Extractor<float> {
private:
    ECapacities idCapacity_;
    Extractor<Army> * ea_;

public:
    ExtractorMinCX(Extractor<Army> * ea, ECapacities idCapacity) : ea_(ea), idCapacity_(idCapacity) {}

    float get(Unit u, Army& a, Army& o) const {
        Army a = ea_->get(u, a, o);

        // Value of Capacity Max
        float min = std::numeric_limits<float>::max();

        for (auto &unit : a.getUnitsList()) {
            float tmp = unit->getCapacity(idCapacity_)->getValue();
            if (tmp < min)
                min = tmp;
        }

        return min;
    }
};

#endif // _EXTRACTORMAXCX_HPP_