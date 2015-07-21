#ifndef _LEAFEMPTY_H_
#define _LEAFEMPTY_H_

#include "Node.hpp"
#include "EmptyAction.hpp"

class LeafEmpty : public Node {
public:
    LeafEmpty() {}
    std::unique_ptr<Action> getAction(Unit& u, Army& a, Army& o) const { return std::unique_ptr<Action>(new EmptyAction(u)); }
};

#endif // _LEAFEMPTY_H_