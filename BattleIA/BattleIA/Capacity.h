#ifndef _CAPACITY_H
#define _CAPACITY_H
#include "stdafx.h"

enum ECapacities: unsigned int
{
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
	virtual	void	downgrade();
	size_t			getLevel() const;
	float			getValue() const;
	virtual void	setLevel(size_t level);

protected:
	size_t			m_level;
	float			m_value;

	virtual void 	computeValue() = 0;
};

#endif