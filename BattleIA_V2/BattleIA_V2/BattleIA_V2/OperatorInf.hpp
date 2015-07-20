#ifndef _OPERATORINF_H_
#define _OPERATORINF_H_

#include "Operator.hpp"

class OperatorInf : public Operator {
public:
    bool getResult(const Node *lson, const Node *rson) const {
        return (lson->getValue() < rson->getValue());
    }
private:
};

#endif // _OPERATORINF_H_