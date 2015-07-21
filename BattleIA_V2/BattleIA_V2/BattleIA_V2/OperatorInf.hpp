#ifndef _OPERATORINF_H_
#define _OPERATORINF_H_

#include "Operator.hpp"

class OperatorInf : public Operator {
public:
    bool getResult(const Extractor<float> *lson, const Extractor<float> *rson, Unit& u, Army& a, Army& o) const {
        return (lson->get(u, a, o) < rson->get(u, a, o));
    }
};

#endif // _OPERATORINF_H_