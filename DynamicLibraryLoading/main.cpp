#include <iostream>
#include <cstdio>
#include <string>
#include "LoadedLibrary.h"

#include <vector>

using namespace std;
int main()
{
	cout << "Podaj nazwe biblioteki" << endl;
	string libName;
	cin >> libName;
	LoadedLibrary* userLib = new LoadedLibrary(libName);
	cout << "Podaj liczbe do ktorej mam dodac jeden" << endl;
	int userInt;
	cin >> userInt;
	cout << "Dodalem jeden: " << userLib->addOneToInt(userInt) << endl;
//sprawdzenie czy istnieje wyciek pamieci
	/*
	vector<LoadedLibrary*> libsVec;
	for (int i = 0; i < 100000; i++)
	{
		libsVec.push_back(new LoadedLibrary("AddNumbers"));
	}
	for (int i = 0; i < 100000; i++)
	{
		delete libsVec[i];
	}*/
//koniec kodu do testow
	cin.ignore();
	cout << "Nacisnij enter by zakonczyc";
	getchar();
	delete userLib;
}