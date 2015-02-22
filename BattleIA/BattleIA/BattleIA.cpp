// BattleIA.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CArmy arm1(10, 2);
	CArmy arm2(8, 3);
	CIA ia;
	for (int i = 0; i < arm1.getUnitsList().size() && i < arm2.getUnitsList().size(); ++i)
	{
		ia(*arm1.getUnitsList()[i], arm1, arm2)->execute();
		ia(*arm2.getUnitsList()[i], arm2, arm1)->execute();
	}
	return 0;
}