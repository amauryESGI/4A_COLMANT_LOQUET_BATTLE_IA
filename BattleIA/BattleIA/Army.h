#ifndef _ARMY_H
#define _ARMY_H
#include "stdafx.h"

class CArmy
{
public:
	CArmy(const int nbUnit, const int level);
	CArmy(const vector<CUnit*> units);
	~CArmy();

	vector<CUnit*>		getUnitsList() const;
	CUnit&				getUnit(int id) const;
	int					size();
	CUnit&				getNearestUnit(const CPoint& p) const;
	CUnit&				getFurtherUnit(const CPoint& p) const;
	CUnit&				getLowestUnit(int capa_index) const;
	CUnit&				getHighestUnit(int capa_index) const;
	void				purge();

private:
	vector<CUnit*> m_units;

};

#endif
