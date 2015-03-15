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
	vector<CArmy*> armies;
	vector<uint>  scores;
	for (uint l = 0; l < N; ++l)
	{
		armies.push_back(new CArmy(X, Y, to_string(l)));
		scores.push_back(0);
	}
	CIA ia;
	uint i = 0, j = 0, k = 0, lap = 0;
	for (i = 0; i < I; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			for (k = (j == N ? N : j+1); k < N; k = ++k)
			{
				CArmy army1(*armies[j]);
				CArmy army2(*armies[k]);
				army1.save();
				cout << "Armee " << army1.getName() << " contre armee " << army2.getName() << endl;
				int m = 0, n = 0, lap = 0;
				while(true)
				{
					cout << "**************** tour " << lap << " ****************" << endl;
					if (m < army1.getUnitsList().size())
					{
						ia(army1.getUnitsList()[m], army1, army2)->execute();
						army2.purge();
					}
					if (n < army2.getUnitsList().size())
					{
						ia(army2.getUnitsList()[n], army2, army1)->execute();
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
					army1.refreshAllUnit();
					army2.refreshAllUnit();
					//Sleep(100);
				}
				if(army2.getUnitsList().size() == 0)
					scores[j] += army1.getUnitsList().size();
				else
					scores[k] += army2.getUnitsList().size();
				if (scores[j] >= T || scores[k] >= T)
					goto end;
			}
		}	
	}
end:;
	
	//Sort

	CArmy *croisArmy = new CArmy(*armies[0]);
	CArmy *mutArmy = new CArmy(*armies[0]);
	uint iBest = N * 0.1;
	if (N*0.1 > 2)
	{
		//for (uint b = 0; b < N*0.1; ++b)

		for (int a = 1; a < N*0.3; ++a)
		{
			*croisArmy = *croisArmy * (*armies[a]);
			*mutArmy = armies[a]->mutate();
		}
	}

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
	bool ok = false;
	cout << "selectionnez les valeurs suivantes : " << endl
		 << "Nombre de tours : ";
	cin  >> *i;
	cout
		 << "Nombre d'armees : ";
	cin  >> *n;
	cout //<< endl
		 << "Nombre d'unites par armees : ";
	cin  >> *x;
	cout //<< endl
		 << "Niveau global de chaque armee : ";
	cin  >> *y;
	while (ok != true)
	{
		cout << endl
			<< "Score max : ";
		cin >> *t;
		if (*t < ( *n - 1 )*( *x ))
			ok = true;
		else
			cout << "score max trop eleve !";
	}
}

#endif


//-----------------------------------------------------------------------------------
//main B
#ifdef _MAIN_B
int _tmain(int argc, _TCHAR* argv[])
{
	int lvl, nbUnit;
	cout << "niveau global : ";
	cin  >> lvl;
	cout << "nbUnit : ";
	cin  >> nbUnit;
	cout << endl;
	CArmy army1(nbUnit, lvl, "A");
	CArmy army2(nbUnit, lvl, "B");
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
		if (j < army2.getUnitsList().size())
		{
			ia(army2.getUnitsList()[j], army2, army1)->execute();
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
		Sleep(500);
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
