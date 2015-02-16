#ifndef _SPEED_H
#define _SPEED_H
#include "stdafx.h"

class CSpeed:
	public CCapacity
{
public:
	CSpeed();
	~CSpeed();

private:
	void	computeValue();
};

#endif