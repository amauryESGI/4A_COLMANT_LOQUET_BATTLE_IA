#include "stdafx.h"

int CUnit::m_id = 0;

CUnit::CUnit(int level): m_level(level)
{
	m_id++;
	m_pos = CPoint(0, 0);

	m_capacities[Speed]			= new CSpeed();
	m_capacities[HealthPoint]	= new CHealthPoint();
	m_capacities[Armor]			= new CArmor();
	m_capacities[Regeneration]  = new CRegeneration();
	m_capacities[Damage]		= new CDamage();
	m_capacities[Scope]			= new CScope();
	m_capacities[WeaponSpeed]	= new CWeaponSpeed();

	for (int i = 0; i < m_level; i++)
		m_capacities[rand() % 6 ]->upgrade();

	m_codeIA = IACODE(rand() % 16);
}

CUnit::CUnit(IACODE codeIA, int speed, int health, int armor, int regeneration, int damage, int scope, int weaponSpeed)
{
	m_id++;
	m_pos = CPoint(0, 0);
	m_codeIA = codeIA;
	m_capacities[Speed]			= new CSpeed();
	m_capacities[Speed]->setLevel(speed);
	m_capacities[HealthPoint]	= new CHealthPoint();
	m_capacities[HealthPoint]->setLevel(health);
	m_capacities[Armor]			= new CArmor();
	m_capacities[Armor]->setLevel(health);
	m_capacities[Regeneration]  = new CRegeneration();
	m_capacities[Regeneration]->setLevel(health);
	m_capacities[Damage]		= new CDamage();
	m_capacities[Damage]->setLevel(health);
	m_capacities[Scope]			= new CScope();
	m_capacities[Scope]->setLevel(health);
	m_capacities[WeaponSpeed]	= new CWeaponSpeed();
	m_capacities[WeaponSpeed]->setLevel(health);

}

CUnit::~CUnit()
{}

int CUnit::getId() const
{
	return m_id;
}

int CUnit::getLevel() const
{
	return m_level;
}

CPoint CUnit::getPos() const
{
	return m_pos;
}

void CUnit::refresh()
{
	dynamic_cast<CHealthPoint*>(m_capacities[HealthPoint])->setCurrentHealth(m_capacities[Regeneration]->getValue());
	dynamic_cast<CWeaponSpeed*>(m_capacities[WeaponSpeed])->turn();
}

void CUnit::setPos(CPoint pos)
{
	m_pos = pos;
}

bool CUnit::shoot() const
{
	if (dynamic_cast<CWeaponSpeed*>( m_capacities[WeaponSpeed] )->canShoot())
	{
		dynamic_cast<CWeaponSpeed*>( m_capacities[WeaponSpeed] )->shoot();
		return true;
	}
	return false;
}

void CUnit::takeDamage(float value)
{
	value -= m_capacities[Armor]->getValue();
	dynamic_cast<CHealthPoint&>(*m_capacities[HealthPoint]).setCurrentHealth(value);
}

bool CUnit::isAlive() const
{
	return m_capacities[HealthPoint]->getValue() > 0;
}

CArmor& CUnit::getArmor()
{
	return dynamic_cast<CArmor&>(*m_capacities[Armor]);
}

CDamage& CUnit::getDamage()
{
	return dynamic_cast<CDamage&>(*m_capacities[Damage]);
}

CHealthPoint& CUnit::getHealthPoint()
{
	return dynamic_cast<CHealthPoint&>(*m_capacities[HealthPoint]);
}

CRegeneration& CUnit::getRegeneration()
{
	return dynamic_cast<CRegeneration&>(*m_capacities[Regeneration]);
}

CScope& CUnit::getScope()
{
	return dynamic_cast<CScope&>(*m_capacities[Scope]);
}

CSpeed& CUnit::getSpeed()
{
	return dynamic_cast<CSpeed&>(*m_capacities[Speed]);
}

CWeaponSpeed& CUnit::getWeaponSpeed()
{
	return dynamic_cast<CWeaponSpeed&>(*m_capacities[WeaponSpeed]);
}

IACODE CUnit::getIACode() const
{
	return m_codeIA;
}