#include "stdafx.h"



CHealthPoint::CHealthPoint(): CCapacity(), m_currentHealth(10) //TODO : default value ?!
{}


CHealthPoint::~CHealthPoint()
{}

void CHealthPoint::computeValue() {
	m_value = (m_level + 1) * 10;
}

void CHealthPoint::setCurrentHealth(float health) {
	health += m_currentHealth;
	if (health > m_value) {
		m_currentHealth = m_value;
	} else if (health < m_value) {
		m_currentHealth = 0;
	} else {
		m_currentHealth = health;
	}
}

size_t CHealthPoint::getCurrentHealth() const {
	return m_currentHealth;
}

