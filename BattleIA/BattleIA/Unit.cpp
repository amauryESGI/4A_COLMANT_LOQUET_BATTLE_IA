#include "stdafx.h"
#include "Unit.h"

CUnit::CUnit(int level) : m_level(level)
{
	// TODO : Define ID
	// m_id = ??
	m_pos = CPoint(0, 0);

	m_capacities[Speed]			= new CSpeed();
	m_capacities[HealthPoint]	= new CHealthPoint();
	m_capacities[Armor]			= new CArmor();
	m_capacities[Regeneration]	= new CRegeneration();
	m_capacities[Damage]		= new CDamage();
	m_capacities[Scope]			= new CScope();
	m_capacities[WeaponSpeed]	= new CWeaponSpeed();

	for (int i = 0; i < m_level; i++)
	{
		// TODO : Define lvl of capacities
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
	(*m_capacities[HealthPoint]).setCurrentHealth((*m_capacities[Regeneration]).getValue());
	(*m_capacities[WeaponSpeed]).turn();
}

void CUnit::setPos() {
	// TODO : Define setPos()
}

bool CUnit::shoot() const {
	return (*m_capacities[WeaponSpeed]).canShoot();
}

void CUnit::takeDamage(float value) {
	value = -value + (*m_capacities[Armor]).getValue();
	if (value < 0)
		(*m_capacities[HealthPoint]).setCurrentHealth(value);
}

bool CUnit::isAlive() const {
	return (*m_capacities[HealthPoint]).getValue > 0;
}

CArmor& CUnit::getArmor() {
	return *m_capacities[Armor];
}

CDamage& CUnit::getDamage() {
	return *m_capacities[Damage];
}

CHealthPoint& CUnit::getHealthPoint() {
	return *m_capacities[HealthPoint];
}

CRegeneration& CUnit::getRegeneration() {
	return *m_capacities[Regeneration];
}

CScope& CUnit::getScope() {
	return *m_capacities[Scope];
}

CSpeed& CUnit::getSpeed() {
	return *m_capacities[Speed];
}

CWeaponSpeed& CUnit::getWeaponSpeed() {
	return *m_capacities[WeaponSpeed];
}

#pragma region Old Version

//bool CUnit::shoot() const {
//	return m_weaponSpeed.canShoot();
//}
//
//void CUnit::takeDamage(float value) {
//	value = -value + m_armor.getValue();
//	if (value < 0)
//		m_healthPoint.setCurrentHealth(value);
//}
//
//bool CUnit::isAlive() const {
//	return m_healthPoint.getValue > 0;
//}

//CArmor& CUnit::getArmor() {
//	return m_armor;
//}
//
//CDamage& CUnit::getDamage() {
//	return m_damage;
//}
//
//CHealthPoint& CUnit::getHealthPoint() {
//	return m_healthPoint;
//}
//
//CRegeneration& CUnit::getRegeneration() {
//	return m_regeneration;
//}
//
//CScope& CUnit::getScope() {
//	return m_scope;
//}
//
//CSpeed& CUnit::getSpeed() {
//	return m_speed;
//}
//
//CWeaponSpeed& CUnit::getWeaponSpeed() {
//	return m_weaponSpeed;
//}
#pragma endregion Old Version