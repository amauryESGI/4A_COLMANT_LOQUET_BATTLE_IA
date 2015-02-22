#include "stdafx.h"

CDamage::CDamage() : CCapacity()
{}


CDamage::~CDamage()
{}

void CDamage::computeValue() {
	m_value = (1 + m_level) * 1.5;
}
