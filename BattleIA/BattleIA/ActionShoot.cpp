#include "stdafx.h"


CActionShoot::CActionShoot(CUnit unit1, CUnit unit2) :  CAction(unit1),
														m_target(unit2)
{}

CActionShoot::~CActionShoot()
{}

void CActionShoot::execute()
{
	m_unit.shoot();
	m_target.takeDamage(m_unit[ECapacities::Damage].getValue());
}