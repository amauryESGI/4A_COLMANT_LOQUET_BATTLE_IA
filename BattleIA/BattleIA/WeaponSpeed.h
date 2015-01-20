#ifndef _WEAPONSPEED_H
#define _WEAPONSPEED_H

#include "Capacity.h"
class CWeaponSpeed:
	public CCapacity
{
public:
	CWeaponSpeed();
	~CWeaponSpeed();

private:
	size_t	m_level;
	float	m_value;

	void	computeValue();
};

#endif