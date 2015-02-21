#include "stdafx.h"

CCapacity::CCapacity() : m_level(1)
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
size_t CCapacity::getLevel() const
{
	return m_level;
}
float CCapacity::getValue() const
{
	return m_value;
}
void CCapacity::setLevel(size_t level)
{
	m_level = level;
}
