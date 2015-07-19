#ifndef _EXTRACTORTLX_HPP_
#define _EXTRACTORTLX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

class ExtractorTLX : public Extractor<Army> {
private:
    Extractor<int>* ei_;
    Extractor<Army>* ea_;
    ECapacities idCapacity_;

public:
    ExtractorTLX(Extractor<int>* ei, Extractor<Army>* ea, int idCapacity) : ei_(ei), ea_(ea), idCapacity_((ECapacities) idCapacity) {}

    Army get(Unit u, Army& a, Army& o) const {
        int seuil = ei_->get(u, a, o);
        std::vector<Unit> subArmy;

        for (auto &unit : ea_->get(u, a, o).getUnitsList())
            if (unit->getCapacity(idCapacity_)->getValue() < seuil)
                subArmy.push_back(u);

        return Army(subArmy);
    }
};

#endif // _EXTRACTORTLX_HPP_