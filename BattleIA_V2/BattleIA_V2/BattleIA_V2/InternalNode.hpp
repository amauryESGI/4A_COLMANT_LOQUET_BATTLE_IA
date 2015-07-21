#ifndef _INTERNALNODE_H_
#define _INTERNALNODE_H_

#include "Node.hpp"
#include "Operator.hpp"
#include "Extractor.hpp"

class InternalNode : public Node {
public:
    InternalNode(Operator *operator_, Node *rson, Node *lson, Extractor<float> *leftSide, Extractor<float> *rightSide) {
        this->_operator = operator_;
        this->_rson = rson;
        this->_lson = lson;
        this->_leftSide = leftSide;
        this->_rightSide = rightSide;
    }

    std::unique_ptr<Action> getAction(Unit u, Army& a, Army& o) const {
        if (_operator->getResult(_leftSide, _rightSide, u, a, o))
            return _lson->getAction(u, a, o);

        return _rson->getAction(u, a, o);
    }

private:
    Operator *_operator;
    Node *_rson;
    Node *_lson;
    Extractor<float> *_leftSide;
    Extractor<float> *_rightSide;
};
#endif // _INTERNALNODE_H_