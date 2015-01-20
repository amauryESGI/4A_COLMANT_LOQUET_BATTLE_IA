#include "stdafx.h"
#include "Damage.h"


CDamage::CDamage()
{}


CDamage::~CDamage()
{}

void CDamage::computeValue() {
	m_value = (1 + m_level) * 3;
}
