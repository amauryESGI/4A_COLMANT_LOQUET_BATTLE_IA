#include "stdafx.h"

CActionMove::CActionMove(CUnit *unit, CPoint *pos) : CAction(unit)
{
	m_pos = new CPoint(pos->getX(), pos->getY());
}


CActionMove::~CActionMove()
{}

void CActionMove::execute()
{
	m_unit->setPos(*m_pos); //TODO : translation ?
	cout << "Unite " 
		 << m_unit->getId() 
		 << " (Armee " 
		 << m_unit->getArmyName() 
		 << ")" 
		 << " bouge en position " 
		 << *m_pos 
		 << endl;
}