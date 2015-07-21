#ifndef _EXTRACTORTHX_HPP_
#define _EXTRACTORTHX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

class ExtractorTHX : public Extractor<Army&> {
private:
    Extractor<int>* ei_;
    Extractor<Army&>* ea_;
    ECapacities idCapacity_;

public:
    ExtractorTHX(Extractor<int>* ei, Extractor<Army&>* ea, int idCapacity) : ei_(ei), ea_(ea), idCapacity_((ECapacities) idCapacity) {}

    Army& get(Unit& u, Army& a, Army& o) const {
        int seuil = ei_->get(u, a, o);
		std::vector<std::shared_ptr<Unit>> subArmy;

        for (auto &unit : ea_->get(u, a, o).getUnitsList())
            if (unit->getCapacity(idCapacity_)->getValue() > seuil)
                subArmy.push_back(std::shared_ptr<Unit>(new Unit(u)));

        return Army(subArmy);
    }

    std::string getIACode() {
        return std::string("TH") + std::to_string(idCapacity_) + ei_->getIACode() + ea_->getIACode();
    }
};

#endif // _EXTRACTORTHX_HPP_