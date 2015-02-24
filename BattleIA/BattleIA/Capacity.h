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
	uint			getLevel() const;
	float			getValue() const;
	virtual void	setLevel(uint level);
	virtual void	setValue(float value);

protected:
	uint			m_level;
	float			m_value;

	virtual void 	computeValue() = 0;
};

#endif