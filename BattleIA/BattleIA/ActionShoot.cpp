#include "stdafx.h"


CActionShoot::CActionShoot(CUnit unit1, CUnit unit2) :  CAction(unit1),
														m_target(unit2)
{}

CActionShoot::~CActionShoot()
{}

void CActionShoot::execute()
{
	//TODO : bouger jusqu'a etre a portée. 
	std::cout << "unit " << m_unit.getId() << " shoot !" << std::endl;
	m_unit.shoot();
	std::cout << "enemy " << m_target.getId() << " took " << m_unit[ECapacities::Damage].getValue() << " damages !" << std::endl;
	m_target.takeDamage(m_unit[ECapacities::Damage].getValue());
}