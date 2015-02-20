#include "stdafx.h"
#define uint unsigned short int

CArmy::CArmy(int nbUnit, int level)
{
	for (int i = 0; i < nbUnit; ++i)
		m_units.push_back(new CUnit(level));
}
CArmy::CArmy(vector<CUnit*> units)
{
	m_units = units;
}

CArmy::~CArmy()
{}

vector<CUnit*> CArmy::getUnitsList()
{
	return m_units;
}
CUnit& CArmy::getUnit(int id)
{
	for (uint i = 0; i < m_units.size(); ++i)
		if (m_units[i]->getId() == id)
			return *m_units[i];
	throw "index out of band";
}
int CArmy::size()
{
	return m_units.size();
}
CUnit& CArmy::getNearestUnit(const CPoint& p)
{
	float f = CPoint::distance(p, m_units[0]->getPos());
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if (CPoint::distance(p, m_units[i]->getPos()) < f)
			index = i;
	return *m_units[index];
}
CUnit& CArmy::getFurtherUnit(const CPoint& p)
{
	float f = CPoint::distance(p, m_units[0]->getPos());
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if (CPoint::distance(p, m_units[i]->getPos()) > f)
			index = i;
	return *m_units[index];
}
CUnit& CArmy::getLowestUnit(int capa_index)
{
	float level = m_units[0][capa_index].getLevel();
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if ( m_units[i][capa_index].getLevel() < level )
			index = i;
	return *m_units[index];
}
CUnit& CArmy::getHighestUnit(int capa_index)
{
	float level = m_units[0][capa_index].getLevel();
	uint index = 0;
	for (uint i = 0; i < m_units.size(); ++i)
		if ( m_units[i][capa_index].getLevel() > level )
			index = i;
	return *m_units[index];
}



void CArmy::purge()
{
	vector<int> index;
	for (uint i = 0; i < m_units.size(); ++i)
		if (m_units[i]->getHealthPoint().getValue() == 0)
			index.push_back(i);
	for (uint i = 0; i < index.size(); ++i)
		m_units.erase(m_units.begin() + index[i]);
}
