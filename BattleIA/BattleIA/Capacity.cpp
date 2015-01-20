#include "stdafx.h"
#include "Capacity.h"


CCapacity::CCapacity()
{}

CCapacity::~CCapacity()
{}

void CCapacity::upgrade()
{
	++m_level;
	computeValue();
}
void CCapacity::downgrade()
{
	if (m_level >= 1)
		--m_level;
	computeValue();
}
size_t CCapacity::getLevel()
{
	return m_level;
}
float CCapacity::getValue()
{
	return m_value;
}
