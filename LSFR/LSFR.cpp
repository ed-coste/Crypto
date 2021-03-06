// LSFR.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<list>
using namespace std;

bool XOR(int indice, bool Kini[], list<bool> etat_interne, int L) {
	list<bool>::iterator it = etat_interne.begin();
	for (int i = 0; i < L - 1 - indice; i++)
	{
		it++;
	}
	bool a = (Kini[indice] && *it);
	indice += 1;
	it--;
	if (indice == L)
	{
		return a ^ (Kini[indice] && *it);
	}
	return a ^ XOR(indice, Kini, etat_interne, L);
}


int main()
{
	int const L = 5;
	bool Kini[L] = { 1, 1, 0, 1, 0 };

	list<bool> etat_interne = { 0, 1, 1, 0, 0 };
	for (int i = 0; i < 10; i++)
	{
		etat_interne.push_front(XOR(0, Kini, etat_interne, L));
		if (*(etat_interne.end()))
		{
			cout << "1" <<endl;
		}
		else 
		{
			cout << "0" << endl;
		}
	}
	system("PAUSE");
    return 0;
}
