#include "stdafx.h"

/**
 * constructor of CArmy
 * @param const unsigned int nbUnit - the number of unit of the army
 * @param const unsigned int level - the global level of all unit of the army
 * @param const string name - the name of the army
 */
CArmy::CArmy(const uint nbUnit, const uint level, const string name): m_name(name)
{
	for (int i = 0; i < nbUnit; ++i)
	{
		CUnit *unit = new CUnit(level);
		unit->setArmyName(name);
		unit->setID(i);
		m_units.push_back(unit);
	}
}
/**
 * constructor of CArmy
 * @param const vector<CUnit*>& units - the list of units of the army
 * @param const string name - the name of the army
 */
CArmy::CArmy(const vector<CUnit*> &units, const string name): m_units(units), m_name(name)
{
	for (int i = 0; i < m_units.size(); ++i)
	{
		m_units[i]->setArmyName(name);
		m_units[i]->setID(i);
	}
}

CArmy::~CArmy()
{}
/**
 * get the unit list
 * @return vector<CUnit*> - the list unit
 */
vector<CUnit*> CArmy::getUnitsList() const
{
	return m_units;
}
/**
 * Get unit from an ID
 * @param unsigned int id - the id of the unit to return
 * @return CUnit - the unit for this id
 */
CUnit& CArmy::getUnit(uint id) const
{
	for (uint i = 0; i < m_units.size(); ++i)
		if (m_units[i]->getId() == id)
			return *m_units[i];
	throw "index out of band";
}
/**
 * Get the current number of units in the army
 * @return unsigned int - the number of unit
 */
uint CArmy::size()
{
	return m_units.size();
}
/**
 * Get the nearest unit from a point
 * @param const CPoint& - the point
 * @return CUnit& - reference of the nearest unit
 */
CUnit& CArmy::getNearestUnit(const CPoint& p) const
{
	float f = CPoint::distance(p, m_units[0]->getPos());
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if (CPoint::distance(p, m_units[i]->getPos()) < f)
			index = i;
	return *m_units[index];
}
/**
 * Get further unit from a point
 * @param const CPoint& - the point
 * @return CUnit& - reference of the further unit
 */
CUnit& CArmy::getFurtherUnit(const CPoint& p) const
{
	float f = CPoint::distance(p, m_units[0]->getPos());
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if (CPoint::distance(p, m_units[i]->getPos()) > f)
			index = i;
	return *m_units[index];
}
/**
 * Get the lowest unit of the passed capacity id
 * @param int capa_index - the index of the capacity
 * @return CUnit& - the unit
 */
CUnit& CArmy::getLowestUnit(uint capa_index) const
{
	float level = m_units[0][capa_index].getLevel();
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if (m_units[i][capa_index].getLevel() < level)
			index = i;
	return *m_units[index];
}
/**
 * Get the higher unit of the passed capacity id
 * @param int capa_index - the index of the capacity
 * @return CUnit& - the unit
 */
CUnit& CArmy::getHighestUnit(uint capa_index) const
{
	float level = m_units[0][capa_index].getLevel();
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if (m_units[i][capa_index].getLevel() > level)
			index = i;
	return *m_units[index];
}
/**
 * Get the name of the Army
 * @return std::string - the name
 */
string CArmy::getName() const
{
	return m_name;
}
/**
 * Purge the army to delete all dead units
 */
void CArmy::purge()
{
	vector<int> index;
	for (uint i = 0; i < m_units.size(); ++i)
		if (m_units[i]->getHealthPoint().getValue() == 0)
			index.push_back(i);
	for (uint i = 0; i < index.size(); ++i)
		m_units.erase(m_units.begin() + index[i]);
}
/**
 * refresh all the unit of the army
 */
void CArmy::refreshAllUnit()
{
	for (uint i = 0; i < m_units.size(); ++i)
		m_units[i]->refresh();
}
