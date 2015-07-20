#ifndef _NODE_H_
#define _NODE_H_

#include "Action.hpp"

class Node {
public:
    virtual Action* getAction(Unit u, Army& a, Army& o) const = 0;
};

#endif // _NODE_H_