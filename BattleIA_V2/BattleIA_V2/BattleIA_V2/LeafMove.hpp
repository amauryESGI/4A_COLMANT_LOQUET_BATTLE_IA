#ifndef _LEAFMOVE_H_
#define _LEAFMOVE_H_

#include "Node.hpp"
#include "MoveAction.hpp"
#include "Extractor.hpp"

class LeafMove : public Node {
public:
    LeafMove(Extractor<Point&>* ep) : _ep(ep) {}
    std::unique_ptr<Action> getAction(Unit& u, Army& a, Army& o) const { return std::unique_ptr<Action>(new MoveAction(u, _ep->get(u, a, o))); }
private:
    Extractor<Point&>* _ep;
};

#endif // _LEAFMOVE_H_