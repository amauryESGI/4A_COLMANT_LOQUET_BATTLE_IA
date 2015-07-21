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
        Army a2 = ea_->get(u, a, o);
        float moy = 0;

        for (auto &unit : a2.getUnitsList())
            moy += unit->getCapacity(idCapacity_)->getValue();

        moy /= a2.size();
        return moy;
    }

    std::string getIACode() {
        return std::string("a") + std::to_string(idCapacity_) + ea_->getIACode();
    }
};

#endif // _EXTRACTORMOYCX_HPP_