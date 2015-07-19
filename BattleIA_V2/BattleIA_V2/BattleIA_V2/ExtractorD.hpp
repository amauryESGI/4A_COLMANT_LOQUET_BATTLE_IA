#ifndef _EXTRACTORD_HPP_
#define _EXTRACTORD_HPP_

#include "Extractor.hpp"
class ExtractorD : public Extractor<float> {
private:
    Extractor<Unit> * eu_;
    Extractor<Point> * ep_;

public:
    ExtractorD(Extractor<Unit>* eu, Extractor<Point>* ep) : eu_(eu), ep_(ep) {}

    float get(Unit u, Army& a, Army& o) const {
        return eu_->get(u, a, o).getPosition().distance(ep_->get(u, a, o));
    }
};

#endif // _EXTRACTORD_HPP_