#include "stdafx.h"


CActionShoot::CActionShoot(CUnit unit1, CUnit unit2) :  m_target(unit2) //TODO : ask seb for unit1
{
	//m_unit = unit1;
}

CActionShoot::~CActionShoot()
{}

void CActionShoot::execute()
{
	m_unit.shoot();
	m_target.takeDamage(m_unit[ECapacities::Damage].getValue());
}