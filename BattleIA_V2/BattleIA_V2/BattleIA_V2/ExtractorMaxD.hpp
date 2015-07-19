#ifndef _EXTRACTORMAXD_HPP_
#define _EXTRACTORMAXD_HPP_

#include "Extractor.hpp"

// ennemi qui a le plus haut dans une capacité ECapacities
class ExtractorMaxD : public Extractor<float> {
private:
    Extractor<Army> * ea_;
    Extractor<Point> * ep_;

public:
    ExtractorMaxD(Extractor<Army> * ea, Extractor<Point> * ep) : ea_(ea), ep_(ep) {}

    float get(Unit u, Army& a, Army& o) const {
        Army a2 = ea_->get(u, a, o);
        Point p = ep_->get(u, a, o);
        float dMax = 0;

        for (auto &unit : a2.getUnitsList()) {
            float dTmp = unit->getPosition().distance(p);
            if (dTmp > dMax)
                dMax = dTmp;
        }

        return dMax;
    }
};

#endif // _EXTRACTORMAXD_HPP_