#ifndef _EXTRACTORDIRECT_HPP_
#define _EXTRACTORDIRECT_HPP_

#include "Extractor.hpp"

class ExtractorDirect : public Extractor<int> {
private:
    int val_;

public:
    ExtractorDirect(int val) : val_(val) {}

    int get(Unit u, Army& a, Army& o) const {
        return val_;
    }

    std::string getIACode() {
        return std::string("[") + std::to_string(val_) + std::string("]");
    }
};

#endif // _EXTRACTORDIRECT_HPP_