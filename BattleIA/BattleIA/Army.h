#ifndef _ARMY_H
#define _ARMY_H
#include "stdafx.h"

class CArmy
{
public:
	CArmy(int nbUnit, int level);
	CArmy(vector<CUnit*> units);
	~CArmy();

	vector<CUnit*> getUnitsList();
	CUnit& getUnit(int id);
	int size();
	CUnit& getNearestUnit(const CPoint& p);
	CUnit& getFurtherUnit(const CPoint& p);
	CUnit& getLowestUnit(int capa_index);
	CUnit& getHighestUnit(int capa_index);
	void purge();

private:
	vector<CUnit*> m_units;

};

#endif
