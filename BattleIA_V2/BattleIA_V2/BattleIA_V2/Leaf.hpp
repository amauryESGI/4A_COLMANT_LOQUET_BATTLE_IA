#ifndef _LEAF_H_
#define _LEAF_H_

#include "Node.hpp"

class Leaf : public Node {
public:
    Leaf(int value) : _value(value) {}
    int getValue() const { return _value; }
private:
    int _value;
};

#endif // _LEAF_H_