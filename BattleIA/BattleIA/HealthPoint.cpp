#include "stdafx.h"

CHealthPoint::CHealthPoint(): CCapacity(), m_maxLife(( m_level + 1 ) * 10)
{
	m_value = m_maxLife;
}


CHealthPoint::~CHealthPoint()
{}

void CHealthPoint::computeValue()
{
	m_maxLife = ( m_level + 1 ) * 10;
}

void CHealthPoint::setMaxLife(float health)
{
	health += m_value;
	if (health > m_maxLife)
		m_value = m_maxLife;
	else if (health < m_maxLife)
		m_value = 0;
	else
		m_value = health;
}

uint CHealthPoint::getMaxLife() const
{
	return m_maxLife;
}

