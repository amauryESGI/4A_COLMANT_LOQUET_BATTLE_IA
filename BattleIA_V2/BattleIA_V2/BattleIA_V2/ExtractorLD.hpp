#ifndef _EXTRACTORLD_HPP_
#define _EXTRACTORLD_HPP_

#include "Extractor.hpp"

// 
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

class ExtractorLD2 : public Extractor<float> {
private:
    Extractor<Army> * ea_;
    Extractor<Point> * ep_;

public:
    ExtractorLD2(Extractor<Army> * ea, Extractor<Point>* ep) : ea_(ea), ep_(ep) {}

    float get(Unit u, Army& a, Army& o) const {
        Point p(ep_->get(u, a, o));

        return p.distance(
            ep_->get(ea_->get(u, a, o).getNearestUnit(p), a, o)
            );
    }
};

#endif // _EXTRACTORLD_HPP_