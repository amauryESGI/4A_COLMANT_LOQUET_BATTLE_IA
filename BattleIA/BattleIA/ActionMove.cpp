#include "stdafx.h"


CActionMove::CActionMove(CUnit unit, CPoint pos) : CAction(unit), 
													m_pos(pos)
{}


CActionMove::~CActionMove()
{}

void CActionMove::execute()
{
	m_unit.setPos(m_pos); //TODO : translation ?
}