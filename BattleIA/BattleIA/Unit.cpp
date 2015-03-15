#include "stdafx.h"
/**
 * constructor of CUnit
 * @param const unsigned int level - the global level of the unit
 */
CUnit::CUnit(const uint level): m_id(0) //default value 0
, m_level(level)
, m_pos(new CPoint(rand() % 50, rand() % 50)) //random position between 0 and 500
, m_codeIA(IACODE(rand() % 16)) //random IACODE between 0 and 16
, m_armyName("") //default name ""
{
	m_capacities[Speed] = new CSpeed();
	m_capacities[HealthPoint] = new CHealthPoint();
	m_capacities[Armor] = new CArmor();
	m_capacities[Regeneration] = new CRegeneration();
	m_capacities[Damage] = new CDamage();
	m_capacities[Scope] = new CScope();
	m_capacities[WeaponSpeed] = new CWeaponSpeed();
	m_capacities[Speed]->upgrade();
	m_capacities[HealthPoint]->upgrade();
	m_capacities[Armor]->upgrade();
	m_capacities[Regeneration]->upgrade();
	m_capacities[Damage]->upgrade();
	m_capacities[Scope]->upgrade();
	m_capacities[WeaponSpeed]->upgrade();


	for (int i = 0; i < m_level; i++)
		m_capacities[rand() % 7]->upgrade();

	//m_codeIA = IACODE(rand() % 16);

	//m_pos = CPoint(rand() % 50, rand() % 50);
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
	, m_pos(new CPoint(rand() % 50, rand() % 50))
	, m_codeIA(codeIA)
	, m_armyName("")
{
	m_capacities[Speed] = new CSpeed();
	m_capacities[HealthPoint] = new CHealthPoint();
	m_capacities[Armor] = new CArmor();
	m_capacities[Regeneration] = new CRegeneration();
	m_capacities[Damage] = new CDamage();
	m_capacities[Scope] = new CScope();
	m_capacities[WeaponSpeed] = new CWeaponSpeed();
	m_capacities[HealthPoint]->upgrade();
	m_capacities[Armor]->upgrade();
	m_capacities[Regeneration]->upgrade();
	m_capacities[Damage]->upgrade();
	m_capacities[Scope]->upgrade();
	m_capacities[WeaponSpeed]->upgrade();

	for (int i = 0; i <= speed; ++i)
		m_capacities[Speed]->upgrade();
	for (int i = 0; i <= health; ++i)
		m_capacities[HealthPoint]->upgrade();
	for (int i = 0; i <= armor; ++i)
		m_capacities[Armor]->upgrade();
	for (int i = 0; i <= regeneration; ++i)
		m_capacities[Regeneration]->upgrade();
	for (int i = 0; i <= armor; ++i)
		m_capacities[Damage]->upgrade();
	for (int i = 0; i <= damage; ++i)
		m_capacities[Scope]->upgrade();
	for (int i = 0; i <= weaponSpeed; ++i)
		m_capacities[WeaponSpeed]->upgrade();
}
CUnit::CUnit(const CUnit& unit): m_armyName(unit.m_armyName)
								, m_codeIA(unit.m_codeIA)
								, m_id(unit.m_id)
								, m_level(unit.m_level)
								, m_pos(unit.m_pos)
{
	m_capacities[Speed] = new CSpeed();
	m_capacities[HealthPoint] = new CHealthPoint();
	m_capacities[Armor] = new CArmor();
	m_capacities[Regeneration] = new CRegeneration();
	m_capacities[Damage] = new CDamage();
	m_capacities[Scope] = new CScope();
	m_capacities[WeaponSpeed] = new CWeaponSpeed();
	m_capacities[HealthPoint]->upgrade();
	m_capacities[Armor]->upgrade();
	m_capacities[Regeneration]->upgrade();
	m_capacities[Damage]->upgrade();
	m_capacities[Scope]->upgrade();
	m_capacities[WeaponSpeed]->upgrade();

	for (int i = 0; i <= unit.getSpeed().getValue(); ++i)
		m_capacities[Speed]->upgrade();
	for (int i = 0; i <= unit.getHealthPoint().getValue(); ++i)
		m_capacities[HealthPoint]->upgrade();
	for (int i = 0; i <= unit.getArmor().getValue(); ++i)
		m_capacities[Armor]->upgrade();
	for (int i = 0; i <= unit.getRegeneration().getValue(); ++i)
		m_capacities[Regeneration]->upgrade();
	for (int i = 0; i <= unit.getDamage().getValue(); ++i)
		m_capacities[Damage]->upgrade();
	for (int i = 0; i <= unit.getScope().getValue(); ++i)
		m_capacities[Scope]->upgrade();
	for (int i = 0; i <= unit.getWeaponSpeed().getValue(); ++i)
		m_capacities[WeaponSpeed]->upgrade();
}
CUnit::~CUnit()
{
	delete( m_pos );
}
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
	return *m_pos;
}
/**
 * Refresh the unit, regenerate it and decrement the cooldown
 */
void CUnit::refresh() const
{
	dynamic_cast<CHealthPoint*>( m_capacities[HealthPoint] )->setValue(getHealthPoint().getValue() + getRegeneration().getValue());
	dynamic_cast<CWeaponSpeed*>( m_capacities[WeaponSpeed] )->turn();
}
/**
 * Set the position of the unit
 * @param const CPoint& pos - the position
 */
void CUnit::setPos(CPoint *pos)
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
		value = getHealthPoint().getValue() - 1;
	//return;
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
/**
 * crossing two units
 * @param const CUnit& unit - the other unit
 * @return CUnit& - the unit crossed with the other
 */
CUnit& CUnit::operator*( const CUnit& unit ) const
{
	vector<uint> caps{1,1,1,1,1,1,1};
	for (uint i = 0; i < 7; ++i)
		caps[i] = this->m_capacities[i]->getLevel() >= unit.m_capacities[i]->getLevel() 
					? this->m_capacities[i]->getLevel() 
					: unit.m_capacities[i]->getLevel();
	IACODE iac = rand() % 10 > 5 ? this->m_codeIA : unit.m_codeIA;
	CUnit rUnit = CUnit(iac, caps[0], caps[1], caps[2], caps[3], caps[4], caps[5], caps[6]);
	rUnit.m_level = this->m_level >= unit.m_level ? this->m_level : unit.m_level;
	return rUnit;
}
/**
 * mutate two units
 * @return CUnit - the mutate unit
 */
CUnit CUnit::mutate()
{
	uint ran = rand() % 6;
	if (m_capacities[ran]->getLevel() > 1)
	{
		uint downgrade = 1 + rand() % m_capacities[ran]->getLevel() - 1;
		uint ran2 = rand() % 6;
		for (uint i = 0; i < downgrade; ++i)
		{
			m_capacities[ran]->downgrade();
			m_capacities[ran2]->upgrade();
		}
		return *this;
	}
	else
		mutate();
}
