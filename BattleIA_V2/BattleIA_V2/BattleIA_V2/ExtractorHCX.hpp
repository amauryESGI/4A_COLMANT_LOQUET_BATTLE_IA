#ifndef _EXTRACTORHCX_HPP_
#define _EXTRACTORHCX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// valeurs d'une capacité ECapacities

class ExtractorHCX : public Extractor<Unit> {
private:
    Extractor<Army> * ea_;
    ECapacities idCapacity_;

public:
    ExtractorHCX(Extractor<Army> * ea, ECapacities idC) : ea_(ea), idCapacity_(idC) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getHigestUnit(idCapacity_);
    }

    std::string getIACode() {
        return std::string("H") + std::to_string(idCapacity_) + ea_->getIACode();
    }
};

#endif // _EXTRACTORHCX_HPP_