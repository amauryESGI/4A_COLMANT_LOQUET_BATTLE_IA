#include "stdafx.h"

/**
 * Default constructor of CWeaponSpeed
 */
CWeaponSpeed::CWeaponSpeed(): CCapacity(), m_coolDown(0)
{}


CWeaponSpeed::~CWeaponSpeed()
{}
/**
 * Set the value for WeaponSpeed when Upgrade() is called
 */
void CWeaponSpeed::computeValue()
{
	m_value = 10 / ( m_level + 1 );
}
/**
 * Get the cool down of the weapon
 * @return unsigned int - the cooldown
 */
uint CWeaponSpeed::getCoolDown() const
{
	return m_coolDown;
}
/**
 * called at the end of a turn to decrement the cooldown
 */
void CWeaponSpeed::turn()
{
	if (m_coolDown >= 1)
		--m_coolDown;
}
/**
 * Shoot someone, set cooldown to the default value
 */
void CWeaponSpeed::shoot()
{
	m_coolDown = m_value;
}
/**
 * Check if unit can shoot
 * @return bool true if cooldown is 0, false in the other case
 */
bool CWeaponSpeed::canShoot() const
{
	return m_coolDown == 0 ? true : false;
}
