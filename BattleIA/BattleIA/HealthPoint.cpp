#include "stdafx.h"
/**
 * Default constructor of CHealthPoint
 */
CHealthPoint::CHealthPoint(): CCapacity(), m_maxLife(( m_level + 1 ) * 10)
{
	m_value = m_maxLife;
}


CHealthPoint::~CHealthPoint()
{}

/**
 * Set the maxValue for HealthPoint when Upgrade() is called
 */
void CHealthPoint::computeValue()
{
	m_maxLife = ( m_level + 1 ) * 10;
}
/**
 * Set the max life of the capacity healthpoint
 * @param int health - the max life
 */
void CHealthPoint::setMaxLife(float health)
{
	health += m_value;
	if (health > m_maxLife)
		m_value = m_maxLife;
	else if (health < m_maxLife)
		m_value = 0;
	else
		m_value = health;
}
/**
 * get the max life of the capacity HealthPoint
 * @return unsigned int - the max life
 */
uint CHealthPoint::getMaxLife() const
{
	return m_maxLife;
}

