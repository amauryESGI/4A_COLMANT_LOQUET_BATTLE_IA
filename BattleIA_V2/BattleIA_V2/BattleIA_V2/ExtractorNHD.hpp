#ifndef _EXTRACTORNHD_HPP_
#define _EXTRACTORNHD_HPP_

#include "Extractor.hpp"

bool compareDistanceH(Unit* a, Unit* b, Point p)
{
	return a->getPosition().distance(p) > b->getPosition().distance(p);
}

class ExtractorNHD : public Extractor<Army> {
private:
    Extractor<int>* ei_;
    Extractor<Army>* ea_;
    Extractor<Point>* ep_;

public:
    ExtractorNHD(Extractor<int>* ei, Extractor<Army>* ea, Extractor<Point>* ep) : ei_(ei), ea_(ea), ep_(ep) {}

    Army get(Unit u, Army& a, Army& o) const {
        Point p = ep_->get(u, a, o);
		std::vector<Unit*> subArmy = ea_->get(u, a, o).getUnitsList();

        std::sort(subArmy.begin(), subArmy.end(), std::bind(compareDistanceH, std::placeholders::_1, std::placeholders::_2, p));
        return Army(std::vector<Unit*>(subArmy.begin(), subArmy.begin() + ei_->get(u, a, o)));
    }
};

#endif // _EXTRACTORNHD_HPP_