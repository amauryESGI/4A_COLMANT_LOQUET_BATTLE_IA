#ifndef _ARMY_H
#define _ARMY_H
#include "stdafx.h"

class CArmy
{
public:
	CArmy(const uint nbUnit, const uint level, string name);
	CArmy(const vector<CUnit*> &units, string name);
	~CArmy();

	vector<CUnit*>		getUnitsList() const;
	CUnit&				getUnit(uint id) const;
	uint				size();
	CUnit&				getNearestUnit(const CPoint& p) const;
	CUnit&				getFurtherUnit(const CPoint& p) const;
	CUnit&				getLowestUnit(uint capa_index) const;
	CUnit&				getHighestUnit(uint capa_index) const;
	void				purge();

	string				getName() const;

	void				refreshAllUnit();
private:
	vector<CUnit*>	m_units;
	string			m_name;

};

#endif //_ARMY_H
