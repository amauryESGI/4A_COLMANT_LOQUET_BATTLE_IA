#ifndef _CIA_H_
#define _CIA_H_
#include "stdafx.h"

class CIA
{
public:
	CIA();
	~CIA();

	CAction& operator()(CUnit unit, CArmy army1, CArmy army2);
private :
	CUnit m_unit;
	CArmy m_army1, m_army2;

};

#endif
