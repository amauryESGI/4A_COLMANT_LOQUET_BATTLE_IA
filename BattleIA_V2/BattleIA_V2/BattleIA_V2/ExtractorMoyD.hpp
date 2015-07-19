#ifndef _EXTRACTORMOYD_HPP_
#define _EXTRACTORMOYD_HPP_

#include "Extractor.hpp"

// ennemi qui a le plus haut dans une capacité ECapacities
class ExtractorMoyD : public Extractor<float> {
private:
    Extractor<Army> * ea_;
    Extractor<Point> * ep_;

public:
    ExtractorMoyD(Extractor<Army> * ea, Extractor<Point> * ep) : ea_(ea), ep_(ep) {}

    float get(Unit u, Army& a, Army& o) const {
        Army a2 = ea_->get(u, a, o);
        Point p = ep_->get(u, a, o);
        float dMoy = 0;

        for (auto &unit : a2.getUnitsList())
            dMoy += unit->getPosition().distance(p);

        dMoy /= a2.size();
        return dMoy;
    }
};

#endif // _EXTRACTORMOYD_HPP_