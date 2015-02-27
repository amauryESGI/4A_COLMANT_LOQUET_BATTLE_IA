#ifndef _CACTIONMOVE_H
#define _CACTIONMOVE_H
#include "stdafx.h"

class CActionMove : public CAction
{
public:
	CActionMove(CUnit *unit, CPoint *pos);
	~CActionMove();
	void execute();
private:
	CPoint *m_pos;
};

#endif
