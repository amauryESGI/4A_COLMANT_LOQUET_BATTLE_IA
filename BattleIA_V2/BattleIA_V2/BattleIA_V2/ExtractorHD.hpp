#ifndef _EXTRACTORHD_HPP_
#define _EXTRACTORHD_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// ennemi qui a le plus de vitesse
class ExtractorHD : public Extractor<Unit> {
private:
    Extractor<Army> * ea_;
    Extractor<Point> * ep_;

public:
    ExtractorHD(Extractor<Army> * ea, Extractor<Point>* ep) : ea_(ea), ep_(ep) {}

    Unit get(Unit u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getFurthestUnit(ep_->get(u, a, o));
    }
};

#endif // _EXTRACTORHD_HPP_