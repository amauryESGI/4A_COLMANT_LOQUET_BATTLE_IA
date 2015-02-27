#ifndef _CATIONSHOOT_H
#define _CATIONSHOOT_H
#include "stdafx.h"

class CActionShoot : public CAction
{
public:
	CActionShoot(CUnit *unit1, CUnit *unit2);
	~CActionShoot();
	void execute();

private:
	CUnit *m_target;
};

#endif