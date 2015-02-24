#ifndef _WEAPONSPEED_H
#define _WEAPONSPEED_H

#include "stdafx.h"
class CWeaponSpeed:
	public CCapacity
{
public:
	CWeaponSpeed();
	~CWeaponSpeed();

	uint	getCoolDown() const;
	void	turn();
	void	shoot();
	bool	canShoot() const;

private:
	uint	m_coolDown;
	void	computeValue();
};

#endif