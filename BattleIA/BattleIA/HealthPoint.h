#ifndef _HEALTHPOINT_H
#define _HEALTHPOINT_H
#include "stdafx.h"

class CHealthPoint:
	public CCapacity
{
public:
	CHealthPoint();
	~CHealthPoint();

	void	setMaxLife(float health);
	uint	getMaxLife() const;

private:
	uint	m_maxLife;

	void	computeValue();
};

#endif //_HEALTHPOINT_H