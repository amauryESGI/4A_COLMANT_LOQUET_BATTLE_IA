#ifndef _CACTION_H
#define _CACTION_H
#include "stdafx.h"

class CAction
{
public:
	CAction(CUnit unit);
	~CAction();
	virtual void execute();

protected:
	CUnit m_unit;
};

#endif
