#ifndef _EXTRACTORNHX_HPP_
#define _EXTRACTORNHX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

class ExtractorNHX : public Extractor<Army&> {
private:
    Extractor<int>* ei_;
    Extractor<Army&>* ea_;
    ECapacities idCapacity_;

public:
    ExtractorNHX(Extractor<int>* ei, Extractor<Army&>* ea, int idCapacity) : ei_(ei), ea_(ea), idCapacity_((ECapacities)idCapacity) {}

    Army& get(Unit& u, Army& a, Army& o) const {
        std::vector<std::shared_ptr<Unit>> subArmy = ea_->get(u, a, o).getUnitsList();
        int id = idCapacity_;

		std::sort(subArmy.begin(), subArmy.end(), [&id](const std::shared_ptr<Unit> a, const std::shared_ptr<Unit> b) {
			return a->getCapacity(id)->getLevel() > b->getCapacity(id)->getLevel();
		});
        return Army(std::vector<std::shared_ptr<Unit>>(subArmy.begin(), subArmy.begin() + ei_->get(u, a, o)));
    }

    std::string getIACode() {
        return std::string("NH") + std::to_string(idCapacity_) + ei_->getIACode() + ea_->getIACode();
    }
};


#endif // _EXTRACTORNHX_HPP_