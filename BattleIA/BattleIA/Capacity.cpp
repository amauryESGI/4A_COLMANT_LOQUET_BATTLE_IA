#include "stdafx.h"
/**
 * Default constructor of CCapacity
 */
CCapacity::CCapacity(): m_level(1), m_value(0)
{}

CCapacity::~CCapacity()
{}

/**
 * Upgrade a capacity
 */
void CCapacity::upgrade()
{
	++m_level;
	computeValue();
}
/**
 * Downgrade a capacity
 */
void CCapacity::downgrade()
{
	if (m_level >= 1)
		--m_level;
	computeValue();
}
/**
 * Get the level of a capacity
 */
uint CCapacity::getLevel() const
{
	return m_level;
}
/**
 * Get the value of the capacity
 * @return float value - the value
 */

float CCapacity::getValue() const
{
	return m_value;
}
/**
 * Set the level of a capacity
 * @param unsigned int level - the level
 */
void CCapacity::setLevel(uint level)
{
	m_level = level;
}
/**
 * Set the value of a capacity
 * @param float value - the value
 */
void CCapacity::setValue(float value)
{
	m_value = value;
}
