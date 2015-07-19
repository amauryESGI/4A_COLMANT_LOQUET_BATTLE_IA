#ifndef _EXTRACTORNHD_HPP_
#define _EXTRACTORNHD_HPP_

#include "Extractor.hpp"

class ExtractorNHD : public Extractor<Army> {
private:
    Extractor<int>* ei_;
    Extractor<Army>* ea_;
    Extractor<Point>* ep_;

public:
    ExtractorNHD(Extractor<int>* ei, Extractor<Army>* ea, Extractor<Point>* ep) : ei_(ei), ea_(ea), ep_(ep) {}

    Army get(Unit u, Army& a, Army& o) const {
        Point p = ep_->get(u, a, o);
        auto subArmy(ea_->get(u, a, o).getUnitsList());

        std::sort(subArmy.begin(), subArmy.end(), [&p](const std::shared_ptr<Unit> a, const std::shared_ptr<Unit> b) {
            return a->getPosition().distance(p) > b->getPosition().distance(p);
        });
        return Army(std::vector<std::unique_ptr<Unit>>(subArmy.begin(), subArmy.begin() + ei_->get(u, a, o)));
    }
};

#endif // _EXTRACTORNHD_HPP_