// BattleIA.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

/* in function of configuration (Main C or Main B)
 * we will run the corresponding main
 */

#ifdef _MAIN_C
void getInput(int *i, int *t, int *n, int *x, int *y);

int _tmain(int argc, _TCHAR* argv[])
{
	int I, T, N, X, Y;
	getInput(&I, &T, &N, &X, &Y);
	vector<CArmy> armies;
	vector<uint>  scores;
	for (uint l = 0; l < N; ++l)
		armies.push_back(CArmy(X, Y, to_string(l)));
	CIA ia;
	uint i = 0, j = 0, k = 0, lap = 0;
	for (i = 0; i < I; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			CArmy army1(armies[j].getUnitsList(), armies[j].getName());
			for (k = j == 0 ? ++k : 0; k < N - 1; k = k == j-1 ? k+2 : ++k)
			{
				CArmy army2(armies[k].getUnitsList(), armies[k].getName());
				int m = 0, n = 0, lap = 0;
				while(true)
				{
					cout << "**************** tour " << lap << " ****************" << endl;
					if (m < army1.getUnitsList().size())
					{
						ia(army1.getUnitsList()[m], army1, army2)->execute();
						army2.purge();
					}
					if (m < army2.getUnitsList().size())
					{
						ia(army2.getUnitsList()[m], army2, army1)->execute();
						army1.purge();
					}
					if (army1.getUnitsList().size() > 0)
						m = m < army1.getUnitsList().size()-1 ? m + 1 : 0;
					else
						break;
					if (army2.getUnitsList().size() > 0)
						n = n < army1.getUnitsList().size()-1 ? n + 1 : 0;
					else
						break;
					++lap;
					//Sleep(1000);
				}

			}
		}		
	}
	
	
	
	/*while(true)
	{
		cout << "**************** tour " << lap << " ****************" << endl;
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
			i = i < army1.getUnitsList().size()-1 ? i + 1 : 0;
		else
			break;
		if (army2.getUnitsList().size() > 0)
			j = j < army1.getUnitsList().size()-1 ? j + 1 : 0;
		else
			break;
		++lap;
		Sleep(1000);
	}*/

}
/**
 * Get the input of user
 * @param int i - the number of turn
 * @param int t - the max score
 * @param int n - the number of army
 * @param int x - the number of unit by army
 * @param int y - the global level of each unit
 */
void getInput(int *i, int *t, int *n, int *x, int *y)
{
	cout << "selectionnez les valeurs suivantes : " << endl
		 << "Nombre de tours : ";
	cin  >> *i;
	cout //<< endl
		 << "Score max : ";
	cin  >> *t; //TODO : mettre ça en dernier et tester T < (N-1)*X
	cout	//<< endl
		 << "Nombre d'armees : ";
	cin  >> *n;
	cout //<< endl
		 << "Nombre d'unites par armees : ";
	cin  >> *x;
	cout //<< endl
		 << "Niveau global de chaque armee : ";
	cin  >> *y;
	cout << endl;
}

#endif


//-----------------------------------------------------------------------------------
//main B
#ifdef _MAIN_B
int _tmain(int argc, _TCHAR* argv[])
{
	CArmy army1(5, 15, "A");
	CArmy army2(5, 15, "B");
	CIA ia;	
	int i = 0, j = 0, lap = 0;
	while(true)
	{
		cout << "**************** tour " << lap << " ****************" << endl;
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
			i = i < army1.getUnitsList().size()-1 ? i + 1 : 0;
		else
			break;
		if (army2.getUnitsList().size() > 0)
			j = j < army1.getUnitsList().size()-1 ? j + 1 : 0;
		else
			break;
		++lap;
		army1.refreshAllUnit();
		army2.refreshAllUnit();
		Sleep(1000);
	}
	cout << "fin de la partie" << endl 
		 << "Score: " << endl
		 << "Army " << army1.getName() << " : " << army1.getUnitsList().size() << endl
		 << "Army " << army2.getName() << " : " << army2.getUnitsList().size() << endl;
	if (army1.getUnitsList().size() == 0)
		cout << "Army " << army2.getName() << " Wins ! *\\o/*" << endl;
	else
		cout << "Army " << army1.getName() << " Wins ! *\\o/*" << endl;


	return 0;
}
#endif
