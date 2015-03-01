#include "stdafx.h"
/**
 * Default constructor of CDamage
 */
CDamage::CDamage() : CCapacity()
{}


CDamage::~CDamage()
{}

/**
 * Set the value for Damage when Upgrade() is called
 */
void CDamage::computeValue() {
	m_value = (1 + m_level) * 1.5;
}
