#include "stdafx.h"

//Parenthesis overloading for applying the AI on the unit provided in parameter
//Return the action which have to be done by the unit in this context
Action* AI::operator()(Unit& unit, Army& allies, Army& opponents)
{
    return unit.getTree()->getAction(unit, allies, opponents);
}
