#ifndef _OPERATORSUP_H_
#define _OPERATORSUP_H_

#include "Operator.hpp"

class OperatorSup : public Operator {
public:
    bool getResult(const Extractor<float> *lson, const Extractor<float> *rson, Unit u, Army& a, Army& o) const {
        return (lson->get(u, a, o) > rson->get(u, a, o));
    }
private:
};

#endif // _OPERATORSUP_H_