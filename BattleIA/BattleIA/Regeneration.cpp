#include "stdafx.h"

/**
 * Default constructor of CRegeneration
 */
CRegeneration::CRegeneration() : CCapacity()
{}


CRegeneration::~CRegeneration()
{}

/**
 * Set the value for Regeneration when Upgrade() is called
 */
void CRegeneration::computeValue() {
	m_value = m_level / 1000;
}
