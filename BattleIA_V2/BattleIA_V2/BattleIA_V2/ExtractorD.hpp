#ifndef _EXTRACTORD_HPP_
#define _EXTRACTORD_HPP_

#include "Extractor.hpp"
class ExtractorD : public Extractor<float> {
private:
    Extractor<Point> * ep_;

public:
    ExtractorD(Extractor<Point>* ep) : ep_(ep) {}

    float get(Unit u, Army& a, Army& o) const {
        return ep_->get(u, a, o).norm(); // TODO : CHECK IF THIS
    }
};

#endif // _EXTRACTORD_HPP_