#include "stdafx.h"
#include "Regeneration.h"


CRegeneration::CRegeneration()
{}


CRegeneration::~CRegeneration()
{}

void CRegeneration::computeValue() {
	m_value = m_level * 3;
}
