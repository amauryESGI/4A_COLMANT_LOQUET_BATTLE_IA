#ifndef _SPEED_H
#define _SPEED_H
#include "Capacity.h"

class CSpeed:
	public CCapacity
{
public:
	CSpeed();
	~CSpeed();

private:
	size_t	m_level;
	float	m_value;

	void	computeValue();
};

#endif