#include "stdafx.h"


CActionMove::CActionMove(CUnit unit, CPoint pos) : CAction(unit), 
													m_pos(&pos)
{}


CActionMove::~CActionMove()
{}

void CActionMove::execute()
{
	std::cout << "Unit " << m_unit.getId() << "go at pos : " << m_pos << std::endl;
	m_unit.setPos(*m_pos); //TODO : translation ?
}