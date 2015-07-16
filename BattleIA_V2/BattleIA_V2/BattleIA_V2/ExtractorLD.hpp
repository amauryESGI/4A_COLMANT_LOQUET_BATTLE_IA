#ifndef _EXTRACTORLD_HPP_
#define _EXTRACTORLD_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// ennemi qui a le plus de vitesse
class ExtractorLD : public Extractor<Unit> {
private:
    Extractor<Army> * ea_;
    Extractor<Point> * ep_;

public:
    ExtractorLD(Extractor<Army> * ea, Extractor<Point>* ep) : ea_(ea), ep_(ep) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getNearestUnit(ep_->get(u, a, o));
    }
};

#endif // _EXTRACTORLD_HPP_