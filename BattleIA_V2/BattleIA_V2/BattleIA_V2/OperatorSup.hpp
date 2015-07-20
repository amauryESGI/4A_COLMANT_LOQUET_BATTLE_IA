#ifndef _OPERATORSUP_H_
#define _OPERATORSUP_H_

#include "Operator.hpp"

class OperatorSup : public Operator {
public:
    bool getResult(const Node *lson, const Node *rson) const {
        return (lson->getValue() > rson->getValue());
    }
private:
};

#endif // _OPERATORSUP_H_