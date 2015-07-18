#ifndef _EXTRACTORB_HPP_
#define _EXTRACTORB_HPP_

#include "Extractor.hpp"

class ExtractorB : public Extractor < Point > {
private:
    Extractor<Army> * ea_;

public:
    ExtractorB(Extractor<Army> * ea) : ea_(ea) {}

    Point get(Unit u, Army& a, Army& o) const {
        Point p = Point();
        Army a = ea_->get(u, a, o);

        for (auto &unit : a.getUnitsList()) {
            p += unit->getPosition();
        }
        p /= a.size();
        return p;
    }
};

#endif // _EXTRACTORB_HPP_