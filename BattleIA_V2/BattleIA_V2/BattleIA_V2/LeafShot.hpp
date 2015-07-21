#ifndef _LEAFSHOT_H_
#define _LEAFSHOT_H_

#include "Node.hpp"
#include "ShotAction.hpp"
#include "Extractor.hpp"

class LeafShot : public Node {
public:
    LeafShot(Extractor<Unit&>* eu) : _eu(eu) {}
    std::unique_ptr<Action> getAction(Unit& u, Army& a, Army& o) const { return std::unique_ptr<Action>(new ShotAction(u, _eu->get(u, a, o))); }
private:
    Extractor<Unit&>* _eu;
};

#endif // _LEAFSHOT_H_