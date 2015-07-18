#ifndef _EXTRACTORHX_HPP_
#define _EXTRACTORHX_HPP_

#include "Extractor.hpp"
#include "ECapacities.hpp"

// ennemi qui a le plus haut dans une capacité ECapacities
class ExtractorHX : public Extractor<Unit> {
private:
    Extractor<Army> * ea_;
    ECapacities idCapacity_;

public:
    ExtractorHX(Extractor<Army> * ea, ECapacities idC) : ea_(ea), idCapacity_(idC) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getHigestUnit(idCapacity_);
    }
};

#endif // _EXTRACTORHX_HPP_