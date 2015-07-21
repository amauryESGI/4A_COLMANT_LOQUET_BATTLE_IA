#ifndef _EXTRACTORNLD_HPP_
#define _EXTRACTORNLD_HPP_

#include "Extractor.hpp"

class ExtractorNLD : public Extractor<Army&> {
private:
    Extractor<int>* ei_;
    Extractor<Army&>* ea_;
    Extractor<Point&>* ep_;

public:
    ExtractorNLD(Extractor<int>* ei, Extractor<Army&>* ea, Extractor<Point&>* ep) : ei_(ei), ea_(ea), ep_(ep) {}

    Army& get(Unit& u, Army& a, Army& o) const {
        Point p = ep_->get(u, a, o);
		std::vector<std::shared_ptr<Unit>> subArmy = ea_->get(u, a, o).getUnitsList();

		std::sort(subArmy.begin(), subArmy.end(), [&p](const std::shared_ptr<Unit> a, const std::shared_ptr<Unit> b) {
			return a->getPosition().distance(p) < b->getPosition().distance(p);
		});
		return Army(std::vector<std::shared_ptr<Unit>>(subArmy.begin(), subArmy.begin() + ei_->get(u, a, o)));
    }

    std::string getIACode() {
        return std::string("NLD") + ei_->getIACode() + ea_->getIACode() + ep_->getIACode();
    }
};

#endif // _EXTRACTORNLD_HPP_