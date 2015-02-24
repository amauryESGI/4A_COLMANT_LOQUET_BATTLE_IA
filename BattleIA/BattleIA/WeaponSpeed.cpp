#include "stdafx.h"



CWeaponSpeed::CWeaponSpeed(): CCapacity(), m_coolDown(0) //TODO : default value ?!
{}


CWeaponSpeed::~CWeaponSpeed()
{}

void CWeaponSpeed::computeValue() {
	m_value = 1000 / (m_level + 1);
}

uint CWeaponSpeed::getCoolDown() const {
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
	return m_coolDown == 0 ? false : true;
}
