#include "stdafx.h"
/**
 * Default constructor of CArmor
 */
CArmor::CArmor() : CCapacity()
{}


CArmor::~CArmor()
{}

/**
 * Set the value for Armor when Upgrade() is called
 */
void CArmor::computeValue()
{
	m_value = m_level / 2;
}