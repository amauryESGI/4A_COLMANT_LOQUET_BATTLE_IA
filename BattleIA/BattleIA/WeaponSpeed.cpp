#include "stdafx.h"
#include "WeaponSpeed.h"


CWeaponSpeed::CWeaponSpeed()
{}


CWeaponSpeed::~CWeaponSpeed()
{}

void CWeaponSpeed::computeValue() {
	m_value = 1000 / (m_level + 1);
}