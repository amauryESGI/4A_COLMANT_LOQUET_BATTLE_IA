#ifndef _EXTRACTOR_HPP_
#define _EXTRACTOR_HPP_

#include "Army.hpp"
#include "Unit.hpp"

template <typename R>
class Extractor {
public:
    virtual R get(Unit u, Army& a, Army& o) const = 0;
};
#endif // _EXTRACTOR_HPP_