#ifndef _SCOPE_H
#define _SCOPE_H
#include "stdafx.h"
class CScope:
	public CCapacity
{
public:
	CScope();
	~CScope();

private:
	void	computeValue();
};

#endif //_SCOPE_H