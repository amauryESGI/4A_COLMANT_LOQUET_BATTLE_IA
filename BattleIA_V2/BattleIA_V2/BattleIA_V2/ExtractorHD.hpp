#ifndef _EXTRACTORHD_HPP_
#define _EXTRACTORHD_HPP_

#include "Extractor.hpp"
#include "Army.hpp"
#include "Unit.hpp"

// 
class ExtractorHD : public Extractor<Unit&> {
private:
    Extractor<Army&> * ea_;
    Extractor<Point&> * ep_;

public:
    ExtractorHD(Extractor<Army&> * ea, Extractor<Point&>* ep) : ea_(ea), ep_(ep) {}

    Unit& get(Unit& u, Army& a, Army& o) const {
        return ea_->get(u, a, o).getFurthestUnit(ep_->get(u, a, o));
    }

    std::string getIACode() {
        return std::string("HD") + ea_->getIACode() + ep_->getIACode();
    }
};

#endif // _EXTRACTORHD_HPP_