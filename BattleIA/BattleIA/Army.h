#ifndef _ARMY_H
#define _ARMY_H
#include "stdafx.h"

class CArmy
{
public:
	CArmy(const int nbUnit, const int level, string name);
	CArmy(const vector<CUnit*> &units, string name);
	~CArmy();

	vector<CUnit*>		getUnitsList() const;
	CUnit&				getUnit(int id) const;
	int					size();
	CUnit&				getNearestUnit(const CPoint& p) const;
	CUnit&				getFurtherUnit(const CPoint& p) const;
	CUnit&				getLowestUnit(int capa_index) const;
	CUnit&				getHighestUnit(int capa_index) const;
	void				purge();

	string				getName() const;

	void				refreshAllUnit();
private:
	vector<CUnit*>	m_units;
	string			m_name;

};

#endif
