#ifndef _CAPACITY_H
#define _CAPACITY_H
#include "stdafx.h"

enum ECapacities : unsigned int {
	Speed,
	HealthPoint,
	Armor,
	Regeneration,
	Damage,
	Scope,
	WeaponSpeed
};

class CCapacity
{
public:
	CCapacity();
	~CCapacity();

	virtual void	upgrade();
	void			downgrade();
	size_t			getLevel();
	float			getValue();
	virtual void	setLevel(size_t level);
	
protected:
	size_t			m_level;
	float			m_value;

	virtual void 	computeValue() = 0;
};

#endif