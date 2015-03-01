#ifndef _CACTION_H
#define _CACTION_H
// Action.h : Classe mere
//
#include "stdafx.h"

class CAction
{
public:
	CAction(CUnit *unit);
	~CAction();
	virtual void execute() = 0;

protected:
	CUnit *m_unit;/*current unit*/
};

#endif //_CACTION_H
