#include "stdafx.h"



CRegeneration::CRegeneration() : CCapacity()
{}


CRegeneration::~CRegeneration()
{}

void CRegeneration::computeValue() {
	m_value = m_level / 1000;
}
