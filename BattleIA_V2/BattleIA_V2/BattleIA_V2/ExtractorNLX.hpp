#ifndef _EXTRACTORNLX_HPP_
#define _EXTRACTORNLX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

bool compareLevelL(Unit* a, Unit* b, int cap_id)
{
	return a->getCapacity(cap_id)->getLevel() > b->getCapacity(cap_id)->getLevel();
}

class ExtractorNLX : public Extractor<Army> {
private:
    Extractor<int>* ei_;
    Extractor<Army>* ea_;
    ECapacities idCapacity_;

public:
    ExtractorNLX(Extractor<int>* ei, Extractor<Army>* ea, int idCapacity) : ei_(ei), ea_(ea), idCapacity_((ECapacities) idCapacity) {}

    Army get(Unit u, Army& a, Army& o) const {
		std::vector<Unit*> subArmy = ea_->get(u, a, o).getUnitsList();
        int id = idCapacity_;

        std::sort(subArmy.begin(), subArmy.end(), std::bind(compareLevelL, std::placeholders::_1, std::placeholders::_2, id));

        return Army(std::vector<Unit*>(subArmy.begin(), subArmy.begin() + ei_->get(u, a, o)));
    }
};


#endif // _EXTRACTORNLX_HPP_