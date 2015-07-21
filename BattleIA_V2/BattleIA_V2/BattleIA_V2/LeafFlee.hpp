#ifndef _LEAFFLEE_H_
#define _LEAFFLEE_H_

#include "Node.hpp"
#include "FleeAction.hpp"
#include "Extractor.hpp"

class LeafFlee : public Node {
public:
    LeafFlee(Extractor<Point>* ep) : _ep(ep) {}
    Action* getAction(Unit u, Army& a, Army& o) const { return new FleeAction(u, _ep->get(u, a, o)); }
private:
    Extractor<Point>* _ep;
};

#endif // _LEAFFLEE_H_