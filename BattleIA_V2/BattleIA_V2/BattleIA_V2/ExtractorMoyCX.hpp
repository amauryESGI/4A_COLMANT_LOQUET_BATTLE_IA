#ifndef _EXTRACTORMOYCX_HPP_
#define _EXTRACTORMOYCX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus haut dans une capacité ECapacities
class ExtractorMoyCX : public Extractor<float> {
private:
    ECapacities idCapacity_;
    Extractor<Army> * ea_;

public:
    ExtractorMoyCX(Extractor<Army> * ea, ECapacities idCapacity) : ea_(ea), idCapacity_(idCapacity){}

    float get(Unit u, Army& a, Army& o) const {
        Army a = ea_->get(u, a, o);
        float moy = 0;

        for (auto &unit : a.getUnitsList())
            moy += unit->getCapacity(idCapacity_)->getValue();

        moy /= a.size();
        return moy;
    }
};

#endif // _EXTRACTORMOYCX_HPP_