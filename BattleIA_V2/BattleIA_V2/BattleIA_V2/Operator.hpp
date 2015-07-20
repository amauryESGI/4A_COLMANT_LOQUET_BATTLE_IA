#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include "Node.hpp"

class Operator {
public:
    virtual bool getResult(const Node *lson, const Node *rson) const = 0;
private:
};

#endif // _OPERATOR_H_