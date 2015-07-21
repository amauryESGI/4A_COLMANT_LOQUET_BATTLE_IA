#ifndef _EXTRACTOR_HPP_
#define _EXTRACTOR_HPP_

#include "Army.hpp"
#include "Unit.hpp"
#include <functional>
#include <complex.h>

template <typename R>
class Extractor {
public:
    virtual R get(Unit u, Army& a, Army& o) const = 0;
    virtual std::string getIACode() { return std::string(""); };

    static  std::string getRandomIACode(int i) { return std::string(""); };
};
#endif // _EXTRACTOR_HPP_