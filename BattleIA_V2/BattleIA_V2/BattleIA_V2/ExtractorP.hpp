#ifndef _EXTRACTORP_HPP_
#define _EXTRACTORP_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"
#include "Point.hpp"

class ExtractorP : public Extractor<Point> {
private:
    Extractor<Unit>* eu_;
public:
    ExtractorP(Extractor<Unit>* eu) : eu_(eu) {}

    Point get(Unit u, Army& a, Army& o) const
    {
        return eu_->get(u, a, o).getPosition();
    }

    std::string getIACode() {
        return std::string("P") + eu_->getIACode();
    }
};

#endif // _EXTRACTORP_HPP_