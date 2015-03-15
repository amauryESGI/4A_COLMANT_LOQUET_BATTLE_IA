#ifndef _ARMY_H
#define _ARMY_H
#include "stdafx.h"

class CArmy
{
public:
	CArmy(const uint nbUnit, const uint level, string name);
	CArmy(const vector<CUnit*> &units, string name);
	CArmy(const CArmy& army);
	~CArmy();

	vector<CUnit*>		getUnitsList() const;
	CUnit&				getUnit(uint id) const;
	uint				size();
	CUnit&				getNearestUnit(const CPoint& p) const;
	CUnit&				getFurtherUnit(const CPoint& p) const;
	CUnit&				getLowestUnit(uint capa_index) const;
	CUnit&				getHighestUnit(uint capa_index) const;
	void				purge();

	CArmy&				operator*( const CArmy& army );
	void				save();
	string				getName() const;
	CArmy				mutate();
	void				refreshAllUnit();
private:
	vector<CUnit*>	m_units;
	string			m_name;
	uint			m_level;

};

#endif //_ARMY_H
