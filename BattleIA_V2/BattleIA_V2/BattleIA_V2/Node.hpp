#ifndef _NODE_H_
#define _NODE_H_

#include "Action.hpp"
#include "Army.hpp"

class Node {
public:
    virtual std::unique_ptr<Action> getAction(Unit& u, Army& a, Army& o) const = 0;
};

#endif // _NODE_H_