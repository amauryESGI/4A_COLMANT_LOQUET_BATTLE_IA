#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include "Node.hpp"
#include "Extractor.hpp"

class Operator {
public:
    virtual bool getResult(const Extractor<float> *lson, const Extractor<float> *rson, Unit& u, Army& a, Army& o) const = 0;
private:
};

#endif // _OPERATOR_H_