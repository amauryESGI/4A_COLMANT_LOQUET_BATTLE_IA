#ifndef _HEALTHPOINT_H
#define _HEALTHPOINT_H
#include "stdafx.h"

class CHealthPoint:
	public CCapacity
{
public:
	CHealthPoint();
	~CHealthPoint();

	void	setCurrentHealth(float health);
	size_t	getCurrentHealth() const;

private:
	size_t	m_currentHealth;

	void	computeValue();
};

#endif