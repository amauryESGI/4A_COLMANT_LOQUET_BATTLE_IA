#ifndef _CIA_H_
#define _CIA_H_
#include "stdafx.h"

class CIA
{
public:
	CAction* operator()(CUnit *unit, const CArmy &army1, const CArmy &army2) const;
};

#endif //_CIA_H_
