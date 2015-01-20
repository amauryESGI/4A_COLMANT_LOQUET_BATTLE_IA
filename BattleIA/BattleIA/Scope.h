#ifndef _SCOPE_H
#define _SCOPE_H
#include "Capacity.h"
class CScope:
	public CCapacity
{
public:
	CScope();
	~CScope();

private:
	size_t	m_level;
	float	m_value;

	void	computeValue();
};

#endif