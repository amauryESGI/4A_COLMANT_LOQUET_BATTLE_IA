#ifndef _HEALTHPOINT_H
#define _HEALTHPOINT_H
#include "Capacity.h"
class CHealthPoint:
	public CCapacity
{
public:
	CHealthPoint();
	~CHealthPoint();

	void	setCurrentHealth(const size_t health);
	size_t	getCurrentHealth() const;

private:
	size_t	m_level;
	float	m_value;
	size_t	m_currentHealth;

	void	computeValue();
};

#endif