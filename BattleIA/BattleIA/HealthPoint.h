#ifndef _HEALTHPOINT_H
#define _HEALTHPOINT_H
#include "Capacity.h"
class CHealthPoint:
	public CCapacity
{
public:
	CHealthPoint();
	~CHealthPoint();

private:
	size_t	m_level;
	float	m_value;

	void	computeValue();
};

#endif