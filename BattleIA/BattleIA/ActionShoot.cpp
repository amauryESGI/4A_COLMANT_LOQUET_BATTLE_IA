#include "stdafx.h"


CActionShoot::CActionShoot(const CUnit &unit1, const CUnit &unit2) :  CAction(unit1),
																	m_target(unit2)
{}

CActionShoot::~CActionShoot()
{}

void CActionShoot::execute()
{
	//TODO : bouger jusqu'a etre a portée. 
	cout << "unit " << m_unit.getId() << " shoot !" <<endl;
	m_unit.shoot();
	cout << "enemy " << m_target.getId() << " took " << m_unit[ECapacities::Damage].getValue() << " damages !" << endl;
	m_target.takeDamage(m_unit[ECapacities::Damage].getValue());
}