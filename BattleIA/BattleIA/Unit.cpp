#include "stdafx.h"
#include "Unit.h"

CUnit::CUnit(int level) : m_level(level)
{
	for (int i = 0; i < m_level; i++)
	{

	}
}

CUnit::~CUnit()
{}

int CUnit::getId() const {
	return m_id;
}

int CUnit::getLevel() const {
	return m_level;
}

CPoint CUnit::getPos() const {
	return m_pos;
}

void CUnit::refresh() {
	m_healthPoint.setCurrentHealth(m_regeneration.getValue());
	m_weaponSpeed.turn();
}

void CUnit::setPos() {
	// TODO : Define setPos()
}

bool CUnit::shoot() const {
	return m_weaponSpeed.canShoot();
}

void CUnit::takeDamage(float value) {
	value = -value + m_armor.getValue();
	if (value < 0)
		m_healthPoint.setCurrentHealth(value);
}

bool CUnit::isAlive() const {
	return m_healthPoint.getValue > 0;
}

CArmor& CUnit::getArmor() {
	return m_armor;
}

CDamage& CUnit::getDamage() {
	return m_damage;
}

CHealthPoint& CUnit::getHealthPoint() {
	return m_healthPoint;
}

CRegeneration& CUnit::getRegeneration() {
	return m_regeneration;
}

CScope& CUnit::getScope() {
	return m_scope;
}

CSpeed& CUnit::getSpeed() {
	return m_speed;
}

CWeaponSpeed& CUnit::getWeaponSpeed() {
	return m_weaponSpeed;
}