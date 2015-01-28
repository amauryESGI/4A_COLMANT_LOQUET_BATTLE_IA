#include "stdafx.h"
#include "WeaponSpeed.h"


CWeaponSpeed::CWeaponSpeed()
{}


CWeaponSpeed::~CWeaponSpeed()
{}

void CWeaponSpeed::computeValue() {
	m_value = 1000 / (m_level + 1);
}

size_t CWeaponSpeed::getCoolDown() const {
	return m_coolDown;
}

void CWeaponSpeed::turn() {
	if (m_coolDown >= 1)
		--m_coolDown;
}

void CWeaponSpeed::shoot() {
	m_coolDown = m_value;
}

bool CWeaponSpeed::canShoot() const {
	// TODO: A TESTER m_coolDown? false : true;
	return m_coolDown > 0 ? false : true;
}
