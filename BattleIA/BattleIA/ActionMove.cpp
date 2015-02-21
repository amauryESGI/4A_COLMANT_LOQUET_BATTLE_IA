#include "stdafx.h"


CActionMove::CActionMove(const CUnit &unit, const CPoint &pos) : CAction(unit), 
																 m_pos(pos)
{}


CActionMove::~CActionMove()
{}

void CActionMove::execute()
{
	cout << "Unit " << m_unit.getId() << " go at pos : " << m_pos << endl;
	m_unit.setPos(m_pos); //TODO : translation ?
}