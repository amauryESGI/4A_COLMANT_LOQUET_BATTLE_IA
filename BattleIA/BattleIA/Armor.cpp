#include "stdafx.h"

CArmor::CArmor() : CCapacity()
{}


CArmor::~CArmor()
{}

void CArmor::computeValue()
{
	m_value = m_level / 2;
}