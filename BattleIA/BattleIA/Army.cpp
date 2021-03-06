#include "stdafx.h"

/**
 * constructor of CArmy
 * @param const unsigned int nbUnit - the number of unit of the army
 * @param const unsigned int level - the global level of all unit of the army
 * @param const string name - the name of the army
 */
CArmy::CArmy(const uint nbUnit, const uint level, const string name): m_name(name), m_level(level)
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
	m_level = units[0]->getLevel();
}
/**
 * copy constructor of CArmy
 * @param const army& units - the army
 */
CArmy::CArmy(const CArmy &army): m_name(army.m_name), m_level(army.m_level)
{
	 for (int i = 0; i < army.getUnitsList().size(); ++i)
	 {
		 CUnit *unit = new CUnit(army.getUnit(i).getIACode(), army.getUnit(i).getSpeed().getValue(), army.getUnit(i).getHealthPoint().getValue(), army.getUnit(i).getScope().getValue(), army.getUnit(i).getArmor().getValue(), army.getUnit(i).getRegeneration().getValue(), army.getUnit(i).getDamage().getValue(), army.getUnit(i).getWeaponSpeed().getValue());
		 unit->setArmyName(m_name);
		 unit->setID(army.getUnit(i).getId());
		 unit->setPos(new CPoint(army.getUnit(i).getPos()));
		 m_units.push_back(unit);
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
/**
 * mutate two armies
 * @return CArmy - the mutate army
 */
CArmy CArmy::mutate()
{
	uint lvl = m_units[0]->getLevel();
	//m_units.clear();
	vector<CUnit*> units;
	for (uint i = 0; i < m_units.size(); ++i)
		units.push_back(new CUnit(lvl));
	return CArmy(units, this->m_name);
}
/**
 * crossing two armies
 * @param const CArmy& army - the other army
 * @return CArmy& - the army crossed with the other
 */
CArmy& CArmy::operator*( const CArmy& army )
{
	vector<CUnit*> list;
	for (uint i = 0; i < m_units.size(); ++i)
		list.push_back(&( (*m_units[i]) * (*army.m_units[i]) ));
	return CArmy(list, this->m_name);
}
/**
 * save army in a file
 */
void CArmy::save()
{
	ofstream file;
	string name = "army_";
	name.append(to_string(m_units.size()));
	name.append("_");
	name.append(to_string(m_level));
	name.append(".save");
	vector<string> codeIA{ "LD", "HD", "L0", "H0", "L1", "H1", "L2", "H2", "L3", "H3", "L4", "H4", "L5", "H5", "L6", "H6" };
	file.open("..\\" + name, ofstream::out);//| ofstream::app);
	//file.clear();
	for (uint i = 0, j = 0; i < m_units.size(); ++i, ++j)
		file << m_units[i]->getSpeed().getLevel()
			 << " "
			 << m_units[i]->getHealthPoint().getLevel()
			 << " "
			 << m_units[i]->getArmor().getLevel()
			 << " "
			 << m_units[i]->getRegeneration().getLevel()
			 << " "
			 << m_units[i]->getDamage().getLevel()
			 << " "
			 << m_units[i]->getScope().getLevel()
			 << " "
			 << m_units[i]->getWeaponSpeed().getLevel()
			 << " "
			 << codeIA[m_units[i]->getIACode()]
			 << endl
			 ;
	file.close();
}
