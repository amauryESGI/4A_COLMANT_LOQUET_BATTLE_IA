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
        Army a2 = ea_->get(u, a, o);

        for (auto &unit : a2.getUnitsList()) {
            p += unit->getPosition();
        }
        p /= static_cast<float>(a2.size());
        return p;
    }

    std::string getIACode() {
        return std::string("B") + ea_->getIACode();
    }
};

#endif // _EXTRACTORB_HPP_