// BattleIA.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
//TODO : voir le cas de l'armure toujours au dessus des point d'attaque de l'énnemi.
int _tmain(int argc, _TCHAR* argv[])
{
	CArmy army1(10, 15, "A");
	CArmy army2(10, 15, "B");
	CIA ia;
	int i = 0, j = 0;
	while(true)
	{
		if (i < army1.getUnitsList().size())
		{
			ia(army1.getUnitsList()[i], army1, army2)->execute();
			army2.purge();
		}
		if (i < army2.getUnitsList().size())
		{
			ia(army2.getUnitsList()[i], army2, army1)->execute();
			army1.purge();
		}
		if (army1.getUnitsList().size() > 0)
			i = i < army1.getUnitsList().size() ? i + 1 : 0;
		else
			break;
		if (army2.getUnitsList().size() > 0)
			j = j < army1.getUnitsList().size() ? j + 1 : 0;
		else
			break;
	}
	cout << "Score : " << endl
		 << "Army " << army1.getName() << " : " << army1.getUnitsList().size() << endl
		 << "Army " << army2.getName() << " : " << army2.getUnitsList().size() << endl;
	if (army1.getUnitsList().size() == 0)
		cout << "Army " << army2.getName() << " Wins ! *\\o/*" << endl;
	else
		cout << "Army " << army1.getName() << " Wins ! *\\o/*" << endl;
	return 0;
}