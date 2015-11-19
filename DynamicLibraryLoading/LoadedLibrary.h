#pragma once
#include <iostream>
#include <windows.h> 
#include <stdio.h> 
#include <string>
#include <atlstr.h>

using namespace std;
typedef int(__cdecl *TwoIntFunctionPointer_T)(int, int);

class LoadedLibrary
{
public:
	LoadedLibrary(); //tworzy pusty obiekt do ktorego nalezy wczytac biblioteke, niezalecane
	LoadedLibrary(string libraryName); //tworzy obiekt i wczytuje biblioteke
	~LoadedLibrary();
	int loadLibrary(string libraryName); //wczytuje biblioteke, niezalecane, uzywac konstruktora tworzacego gotowy obiekt
	int loadFunctionsFromLib(); //wczytuje funkcje, niezalecane, uzywac konstruktora tworzacego gotowy obiekt

	int addOneToInt(int inputInt);
private:
	HINSTANCE _dynamicLib; //wczytana biblioteka
	TwoIntFunctionPointer_T _addNumbers; //pointer do predefiniowanej funkcji "addNumbers"
	//LPCTSTR* _convertStringToTCHAR(string str); //konwertuje string do LPCTSTR //nie dziala, gubi dane po drodze



	//magic numbers
	const static int _LOAD_ERROR = 1;
	const static int _NO_LOAD_ERROR = 0;
};

