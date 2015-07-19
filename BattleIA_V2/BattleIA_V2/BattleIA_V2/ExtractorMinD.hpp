#ifndef _EXTRACTORMIND_HPP_
#define _EXTRACTORMIND_HPP_

#include "Extractor.hpp"

// ennemi qui a le plus haut dans une capacité ECapacities
class ExtractorMinD : public Extractor<float> {
private:
    Extractor<Army> * ea_;
    Extractor<Point> * ep_;

public:
    ExtractorMinD(Extractor<Army> * ea, Extractor<Point> * ep) : ea_(ea), ep_(ep) {}

    float get(Unit u, Army& a, Army& o) const {
        Army a = ea_->get(u, a, o);
        Point p = ep_->get(u, a, o);

        // Distance Max
        float dMin = std::sqrt(Util::width * Util::width + Util::heigth * Util::heigth);

        for (auto &unit : a.getUnitsList()) {
            float dTmp = unit->getPosition().distance(p);
            if (dTmp < dMin)
                dMin = dTmp;
        }

        return dMin;
    }
};

#endif // _EXTRACTORMIND_HPP_