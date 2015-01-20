#ifndef _SPEED
#define _SPEED
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