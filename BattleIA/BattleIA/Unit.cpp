#include "stdafx.h"

CUnit::CUnit(const int level): m_id(0)
								, m_level(level)
								, m_pos(CPoint(rand() % 50, rand() % 50))
								, m_codeIA(IACODE(rand() % 16))
								, m_armyName("")
{
	m_capacities[Speed]			= new CSpeed();
	m_capacities[HealthPoint]	= new CHealthPoint();
	m_capacities[Armor]			= new CArmor();
	m_capacities[Regeneration]	= new CRegeneration();
	m_capacities[Damage]		= new CDamage();
	m_capacities[Scope]			= new CScope();
	m_capacities[WeaponSpeed]	= new CWeaponSpeed();

	for (int i = 0; i < m_level; i++)
		m_capacities[rand() % 6]->upgrade();

	//m_codeIA = IACODE(rand() % 16);

	//m_pos = CPoint(rand() % 50, rand() % 50); //TODO : a voir ...
}

CUnit::CUnit(const IACODE codeIA, const int speed, const int health, const int armor, const int regeneration, const int damage, const int scope, const int weaponSpeed)
	: m_id(0) 
	, m_level(speed + health + armor + regeneration + damage + scope + weaponSpeed)
	, m_pos(CPoint(rand() % 50, rand() % 50))
	, m_codeIA(codeIA)
	, m_armyName("")
{
	m_capacities[Speed] = new CSpeed();
	m_capacities[Speed]->setLevel(speed);
	m_capacities[HealthPoint] = new CHealthPoint();
	m_capacities[HealthPoint]->setLevel(health);
	m_capacities[Armor] = new CArmor();
	m_capacities[Armor]->setLevel(health);
	m_capacities[Regeneration] = new CRegeneration();
	m_capacities[Regeneration]->setLevel(health);
	m_capacities[Damage] = new CDamage();
	m_capacities[Damage]->setLevel(health);
	m_capacities[Scope] = new CScope();
	m_capacities[Scope]->setLevel(health);
	m_capacities[WeaponSpeed] = new CWeaponSpeed();
	m_capacities[WeaponSpeed]->setLevel(health);

	//m_pos = CPoint(rand() % 50, rand() % 50); //TODO : a voir ...
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

void CUnit::refresh() const
{
	dynamic_cast<CHealthPoint*>( m_capacities[HealthPoint] )->setValue(m_capacities[Regeneration]->getValue());
	dynamic_cast<CWeaponSpeed*>( m_capacities[WeaponSpeed] )->turn();
}

void CUnit::setPos(const CPoint &pos)
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
	if (value - m_capacities[Armor]->getValue() < 0)
		return;
	else
		value -= m_capacities[Armor]->getValue();
	if (getHealthPoint().getValue() - value < 0)
		value = 0;
	else
		value = getHealthPoint().getValue() - value;
	dynamic_cast<CHealthPoint&>( *m_capacities[HealthPoint] ).setValue(value);
}

bool CUnit::isAlive() const
{
	return m_capacities[HealthPoint]->getValue() > 0;
}

CCapacity& CUnit::operator[](const unsigned int id) const
{
	if (id > 6)
		throw "Error index out of range ... How did you do that O_O";

	return *m_capacities[id];
}

CArmor& CUnit::getArmor() const
{
	return dynamic_cast<CArmor&>( *m_capacities[Armor] );
}

CDamage& CUnit::getDamage() const
{
	return dynamic_cast<CDamage&>( *m_capacities[Damage] );
}

CHealthPoint& CUnit::getHealthPoint() const
{
	return dynamic_cast<CHealthPoint&>( *m_capacities[HealthPoint] );
}

CRegeneration& CUnit::getRegeneration() const
{
	return dynamic_cast<CRegeneration&>( *m_capacities[Regeneration] );
}

CScope& CUnit::getScope() const
{
	return dynamic_cast<CScope&>( *m_capacities[Scope] );
}

CSpeed& CUnit::getSpeed() const
{
	return dynamic_cast<CSpeed&>( *m_capacities[Speed] );
}

CWeaponSpeed& CUnit::getWeaponSpeed() const
{
	return dynamic_cast<CWeaponSpeed&>( *m_capacities[WeaponSpeed] );
}

IACODE CUnit::getIACode() const
{
	return m_codeIA;
}

string CUnit::getArmyName() const
{
	return m_armyName;
}
void CUnit::setArmyName(const string& name)
{
	m_armyName = name;
}
void CUnit::setID(uint id)
{
	m_id = id;
}