#ifndef _REGENERATION_H
#define _REGENERATION_H
#include "Capacity.h"
class CRegeneration:
	public CCapacity
{
public:
	CRegeneration();
	~CRegeneration();

private:
	size_t	m_level;
	float	m_value;

	void	computeValue();
};

#endif