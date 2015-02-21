#ifndef _CATIONSHOOT_H
#define _CATIONSHOOT_H
#include "stdafx.h"

class CActionShoot : public CAction
{
public:
	CActionShoot(const CUnit &unit1, const CUnit &unit2);
	~CActionShoot();
	void execute();

private:
	CUnit m_target;
};

#endif