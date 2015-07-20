#ifndef _LEAF_H_
#define _LEAF_H_

#include "Node.hpp"
#include "MoveAction.hpp"
#include "FleeAction.hpp"
#include "EmptyAction.hpp"
#include "ShotAction.hpp"

class LeafMove : public Node {
public:
    LeafMove(Extractor<Point>* ep) : _ep(ep) {}
    Action* getAction(Unit u, Army& a, Army& o) const { return new MoveAction(u, _ep->get(u,a,o) ); }
private:
    Extractor<Point>* _ep;
};

class LeafFlee : public Node {
public:
    LeafFlee(Extractor<Point>* ep) : _ep(ep) {}
    Action* getAction(Unit u, Army& a, Army& o) const { return new FleeAction(u, _ep->get(u, a, o)); }
private:
    Extractor<Point>* _ep;
};

class LeafShot : public Node {
public:
    LeafShot(Extractor<Unit>* eu) : _eu(eu) {}
    Action* getAction(Unit u, Army& a, Army& o) const { return new ShotAction(u, _eu->get(u, a, o)); }
private:
    Extractor<Unit>* _eu;
};

class LeafEmpty : public Node {
public:
    LeafEmpty() {}
    Action* getAction(Unit u, Army& a, Army& o) const { return new EmptyAction(u); }
};

#endif // _LEAF_H_