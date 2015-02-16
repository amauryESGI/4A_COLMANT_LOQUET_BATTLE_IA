#ifndef _CIA_H_
#define _CIA_H_
#include "stdafx.h"

class CIA
{
public:
	CAction& operator()(CUnit unit, CArmy army1, CArmy army2);
};

#endif
