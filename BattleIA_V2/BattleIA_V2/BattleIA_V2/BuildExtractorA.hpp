#ifndef _BUILDEXTRACTOR_HPP_
#define _BUILDEXTRACTOR_HPP_

#include <sstream>

template <typename R>
class BuildExtracteur {
public:
    virtual R build(std::stringstream code) const = 0;
};
#endif // _BUILDEXTRACTOR_HPP_