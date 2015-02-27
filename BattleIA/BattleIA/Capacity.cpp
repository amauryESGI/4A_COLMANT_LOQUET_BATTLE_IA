#include "stdafx.h"

CCapacity::CCapacity(): m_level(1), m_value(0)
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
uint CCapacity::getLevel() const
{
	return m_level;
}
float CCapacity::getValue() const
{
	return m_value;
}
void CCapacity::setLevel(uint level)
{
	m_level = level;
}
void CCapacity::setValue(float value)
{
	m_value = value;
}
