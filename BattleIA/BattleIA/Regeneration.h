#ifndef _REGENERATION_H
#define _REGENERATION_H
#include "stdafx.h"
class CRegeneration:
	public CCapacity
{
public:
	CRegeneration();
	~CRegeneration();

private:
	void	computeValue();
};

#endif