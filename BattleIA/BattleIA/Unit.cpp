#include "stdafx.h"
/**
 * constructor of CUnit
 * @param const unsigned int level - the global level of the unit
 */
CUnit::CUnit(const uint level): m_id(0) //default value 0
								, m_level(level)
								, m_pos(CPoint(rand() % 500, rand() % 500)) //random position between 0 and 500
								, m_codeIA(IACODE(rand() % 16)) //random IACODE between 0 and 16
								, m_armyName("") //default name ""
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

	//m_pos = CPoint(rand() % 50, rand() % 50);
	cout << endl << m_capacities[Speed]->getLevel();
}
/**
 * constructor of CUnit
 * @param const IACODE codeIA - the ia code of the unit
 * @param const uint speed - the speed level of the unit
 * @param const uint health - the health level of the unit
 * @param const uint armor - the armor level of the unit
 * @param const uint regeneration - the regeneration level of the unit
 * @param const uint damage - the global damage of the unit
 * @param const uint scope - the global scope of the unit
 * @param const uint weaponSpeed - the weaponSpeed level of the unit
 */
CUnit::CUnit(const IACODE codeIA, const uint speed, const uint health, const uint armor, const uint regeneration, const uint damage, const uint scope, const uint weaponSpeed)
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

	//m_pos = CPoint(rand() % 50, rand() % 50);
}

CUnit::~CUnit()
{}
/**
 * Get the id of the unit
 * @return int - the id
 */
uint CUnit::getId() const
{
	return m_id;
}
/**
 * Get the level of the unit
 * @return int - the level
 */
uint CUnit::getLevel() const
{
	return m_level;
}
/**
 * Get the position of the unit
 * @return CPoint - the position
 */
CPoint CUnit::getPos() const
{
	return m_pos;
}
/**
 * Refresh the unit, regenerate it and decrement the cooldown
 */
void CUnit::refresh() const
{
	dynamic_cast<CHealthPoint*>( m_capacities[HealthPoint] )->setValue(m_capacities[Regeneration]->getValue());
	dynamic_cast<CWeaponSpeed*>( m_capacities[WeaponSpeed] )->turn();
}
/**
 * Set the position of the unit
 * @param const CPoint& pos - the position
 */
void CUnit::setPos(const CPoint &pos)
{
	m_pos = pos;
}
/**
 * Check if the unit can shoot and shoot in this case
 * @return bool true / false - true if the unit has shoot, false in the other case
 */
bool CUnit::shoot() const
{
	if (dynamic_cast<CWeaponSpeed*>( m_capacities[WeaponSpeed] )->canShoot())
	{
		dynamic_cast<CWeaponSpeed*>( m_capacities[WeaponSpeed] )->shoot();
		return true;
	}
	return false;
}
/**
 * Take damages, the damages are substract with the armor's value of the unit
 * @param float value - the value of the damages
 */
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
/**
 * check if the unit is alive
 * @return bool true / false - true if the unit is alive, false in the other case
 */
bool CUnit::isAlive() const
{
	return m_capacities[HealthPoint]->getValue() > 0;
}
/**
 * operator[] - Get the capacity from an ID
 * @param const unsigned int id - the id of the capacity
 * @return CCapacity& - the capacity
 */
CCapacity& CUnit::operator[](const uint id) const
{
	if (id > 6)
		throw "Error index out of range";
	return *m_capacities[id];
}
/**
 * Get the armor of the unit
 * @return CArmor& - reference of the armor
 */
CArmor& CUnit::getArmor() const
{
	return dynamic_cast<CArmor&>( *m_capacities[Armor] );
}
/**
 * Get the damage of the unit
 * @return CDamage& - reference of the damage
 */
CDamage& CUnit::getDamage() const
{
	return dynamic_cast<CDamage&>( *m_capacities[Damage] );
}
/**
 * Get the health point of the unit
 * @return CHealthPoint& - reference of the health point
 */
CHealthPoint& CUnit::getHealthPoint() const
{
	return dynamic_cast<CHealthPoint&>( *m_capacities[HealthPoint] );
}
/**
 * Get the regeneration of the unit
 * @return CRegeneration& - reference of the regeneration
 */
CRegeneration& CUnit::getRegeneration() const
{
	return dynamic_cast<CRegeneration&>( *m_capacities[Regeneration] );
}
/**
 * Get the scopte of the unit
 * @return CScope& - reference of the scope
 */
CScope& CUnit::getScope() const
{
	return dynamic_cast<CScope&>( *m_capacities[Scope] );
}
/**
 * Get the speed of the unit
 * @return CSeed& - reference of the speed
 */
CSpeed& CUnit::getSpeed() const
{
	return dynamic_cast<CSpeed&>( *m_capacities[Speed] );
}
/**
 * Get the weapon speed of the unit
 * @return CWeaponSpeed& - reference of the weapond speed
 */
CWeaponSpeed& CUnit::getWeaponSpeed() const
{
	return dynamic_cast<CWeaponSpeed&>( *m_capacities[WeaponSpeed] );
}
/**
 * Get the ia code of the unit
 * @return IACODE - the ia code
 */
IACODE CUnit::getIACode() const
{
	return m_codeIA;
}
/**
 * Get the name of the unit
 * @return string - the name
 */
string CUnit::getArmyName() const
{
	return m_armyName;
}
/**
 * Set the name of the unit
 * @param const string& - the name
 */
void CUnit::setArmyName(const string& name)
{
	m_armyName = name;
}
/**
 * Set the id of the unit
 * @param const unsigned int - the id
 */
void CUnit::setID(const uint id)
{
	m_id = id;
}