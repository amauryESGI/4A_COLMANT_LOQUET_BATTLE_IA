#ifndef _FLEE_ACTION_HPP_
#define _FLEE_ACTION_HPP_

#include "Unit.hpp"
#include "Action.hpp"
#include "Point.hpp"
#include <iostream>
#include "Util.hpp"

//Class representing the action to move a unit in direction opposite of a specific position
class FleeAction : public Action {
private:
    Unit* unit_;
    Point position_;

public:

    //Constructor taking in paramters the unit to move and the destination
    FleeAction(Unit& unit, const Point& position) : unit_(&unit), position_(position) {
        // TODO : Fix FleeAction
    }

    //Run the action
    //Log parameter indicate if we write something or not on the standard output
    void execute(bool log = false) {
        if (log)std::cout << "Unit " << unit_->getId() << " flee from " << unit_->getPosition();
        unit_->moveToPosition(position_);
        if (log)std::cout << " to " << unit_->getPosition() << std::endl;
    }
};

#endif