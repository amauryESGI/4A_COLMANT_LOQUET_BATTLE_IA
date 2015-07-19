#ifndef _EXTRACTORNLX_HPP_
#define _EXTRACTORNLX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

class ExtractorNLX : public Extractor<Army> {
private:
    Extractor<int>* ei_;
    Extractor<Army>* ea_;
    ECapacities idCapacity_;

public:
    ExtractorNLX(Extractor<int>* ei, Extractor<Army>* ea, int idCapacity) : ei_(ei), ea_(ea), idCapacity_((ECapacities) idCapacity) {}

    Army get(Unit u, Army& a, Army& o) const {
        auto subArmy(ea_->get(u, a, o).getUnitsList());
        int id = idCapacity_;

        std::sort(subArmy.begin(), subArmy.end(), [&id](const std::shared_ptr<Unit> a, const std::shared_ptr<Unit> b) {
            return a->getCapacity(id)->getLevel() > b->getCapacity(id)->getLevel();
        });

        return Army(std::vector<Unit>(subArmy.begin(), subArmy.begin() + ei_->get(u, a, o)));
    }
};

#endif // _EXTRACTORNLX_HPP_