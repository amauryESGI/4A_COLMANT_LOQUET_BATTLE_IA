#ifndef _EXTRACTORHD_HPP_
#define _EXTRACTORHD_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// 
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

class ExtractorHD2 : public Extractor<float> {
private:
    Extractor<Army> * ea_;
    Extractor<Point> * ep_;

public:
    ExtractorHD2(Extractor<Army> * ea, Extractor<Point>* ep) : ea_(ea), ep_(ep) {}

    float get(Unit u, Army& a, Army& o) const {
        Point p(ep_->get(u, a, o));

        return p.distance(
            ep_->get(ea_->get(u, a, o).getFurthestUnit(p), a, o)
            );
    }
};
#endif // _EXTRACTORHD_HPP_