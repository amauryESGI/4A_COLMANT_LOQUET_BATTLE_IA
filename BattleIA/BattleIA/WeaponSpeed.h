#ifndef _WEAPONSPEED_H
#define _WEAPONSPEED_H

#include "Capacity.h"
class CWeaponSpeed:
	public CCapacity
{
public:
	CWeaponSpeed();
	~CWeaponSpeed();

	size_t	getCoolDown() const;
	void	turn();
	void	shoot();
	bool	canShoot() const;

private:
	size_t	m_level;
	float	m_value;
	size_t	m_coolDown;

	void	computeValue();
};

#endif