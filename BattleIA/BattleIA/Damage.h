#ifndef _DAMAGE_H
#define _DAMAGE_H
#include "stdafx.h"

class CDamage:
	public CCapacity
{
public:
	CDamage();
	~CDamage();

private:
	void	computeValue();
};

#endif //_DAMAGE_H