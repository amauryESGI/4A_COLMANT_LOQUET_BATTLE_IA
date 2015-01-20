#ifndef _ARMOR_H
#define _ARMOR_H
#include "Capacity.h"
class CArmor:
	public CCapacity
{
public:
	CArmor();
	~CArmor();

private:
	size_t	m_level;
	float	m_value;

	void	computeValue();
};

#endif