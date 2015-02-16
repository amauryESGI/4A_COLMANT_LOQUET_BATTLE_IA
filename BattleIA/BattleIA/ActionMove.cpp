#include "stdafx.h"


CActionMove::CActionMove(CUnit unit, CPoint pos) : CAction(unit), 
													m_pos(pos)
{}


CActionMove::~CActionMove()
{}
