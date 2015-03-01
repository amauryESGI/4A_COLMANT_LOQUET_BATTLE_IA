#ifndef _ARMOR_H
#define _ARMOR_H
#include "stdafx.h"
class CArmor:
	public CCapacity
{
public:
	CArmor();
	~CArmor();

private:
	void	computeValue();
};

#endif //_ARMOR_H