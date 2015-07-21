#ifndef _LEAFEMPTY_H_
#define _LEAFEMPTY_H_

#include "Node.hpp"
#include "EmptyAction.hpp"

class LeafEmpty : public Node {
public:
    LeafEmpty() {}
    Action* getAction(Unit u, Army& a, Army& o) const { return new EmptyAction(u); }
};

#endif // _LEAFEMPTY_H_