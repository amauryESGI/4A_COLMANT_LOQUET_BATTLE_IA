#include "stdafx.h"

/**
 * Default constructor of CSpeed
 */
CSpeed::CSpeed(): CCapacity()
{}


CSpeed::~CSpeed()
{}
/**
 * Set the value for Speed when Upgrade() is called
 */
void CSpeed::computeValue()
{
	m_value = m_level + 1;
}