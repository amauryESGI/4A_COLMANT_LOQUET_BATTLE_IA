#include "stdafx.h"
#include "Armor.h"


CArmor::CArmor()
{}


CArmor::~CArmor()
{}

void CArmor::computeValue() {
	m_value = m_level * 2;
}