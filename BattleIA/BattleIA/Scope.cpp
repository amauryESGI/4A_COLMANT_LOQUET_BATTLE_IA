#include "stdafx.h"

/**
 * Default constructor of CScope
 */
CScope::CScope() : CCapacity()
{}


CScope::~CScope()
{}
/**
 * Set the value for Scope when Upgrade() is called
 */
void CScope::computeValue() {
	m_value = 10 + m_level * 2;
}