#ifndef _EXTRACTORH0_HPP_
#define _EXTRACTORH0_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// ennemi qui a le plus de vitesse
class ExtractorH0 : public Extractor<Unit> {
private:
    Extractor<Army> * ea_;

public:
    ExtractorH0(Extractor<Army> * ea, Extractor<Point>* ep) : ea_(ea) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getHigestUnit();
    }
};

#endif // _EXTRACTORH0_HPP_