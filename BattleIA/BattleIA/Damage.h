#ifndef _DAMAGE_H
#define _DAMAGE_H
#include "Capacity.h"
class CDamage:
	public CCapacity
{
public:
	CDamage();
	~CDamage();

private:
	size_t	m_level;
	float	m_value;

	void	computeValue();
};

#endif