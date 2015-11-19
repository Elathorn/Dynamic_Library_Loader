#include "LoadedLibrary.h"



LoadedLibrary::LoadedLibrary()
{
}

LoadedLibrary::LoadedLibrary(string libraryName)
{
	if (loadLibrary(libraryName) == _LOAD_ERROR)
	{
		cerr << "Blad wczytania biblioteki";
		return;
	}
	if (loadFunctionsFromLib() == _LOAD_ERROR)
	{
		cerr << "Blad wczytania funkcji z biblioteki";
		return;
	}


}


LoadedLibrary::~LoadedLibrary()
{
	if (_dynamicLib != NULL)
		if (FreeLibrary(_dynamicLib) == ERROR) //"uwalniamy" biblioteke. Jezeli funkcja ta zwraca 0, oznacza to, ze wystapil blad
		{ //#define ERROR pochodzi z API Windowsa 
			cerr << "Blad przy uwalnianiu biblioteki";
		}
}

int LoadedLibrary::loadLibrary(string libraryNameStr)
{
	LPCTSTR libNameTCHAR;// = _convertStringToTCHAR(libraryNameStr); //konwertujemy stringa do formatu wejscia dla LoadLibrary
	//^ nie dziala, gubi dane po drodze
	
	char * data = new char[libraryNameStr.size() + 1];
	copy(libraryNameStr.begin(), libraryNameStr.end(), data);
	data[libraryNameStr.size()] = '\0';
	USES_CONVERSION;
	libNameTCHAR = A2T(data);
	_dynamicLib = LoadLibrary(libNameTCHAR); //wczytujemy biblioteke
	delete data;
	if (_dynamicLib != NULL) //jezeli nie udalo sie wczytac biblioteki
		return _NO_LOAD_ERROR;
	else
	{
		GetLastError(); //todo: obsluga bledow?
		return _LOAD_ERROR;
	}

}

int LoadedLibrary::loadFunctionsFromLib()
{
	_addNumbers = (TwoIntFunctionPointer_T)GetProcAddress(_dynamicLib, "addNumbers"); //wczytujemy funkcje "addNumbers"
	if (_addNumbers != NULL) //jezeli udalo sie ja wczytac, zwracamy powodzenie
		return _NO_LOAD_ERROR;
	else //w innym wypadku zwracamy blad
		return _LOAD_ERROR;
}

int LoadedLibrary::addOneToInt(int inputInt)
{
	return (_addNumbers)(1, inputInt);
}

/* nie dziala, gubi dane po drodze
LPCTSTR* LoadedLibrary::_convertStringToTCHAR(string str)
{
	LPCTSTR* tcharStr = new LPCTSTR();
	char * data = new char[str.size() + 1];
	copy(str.begin(), str.end(), data);
	data[str.size()] = '\0';
	USES_CONVERSION;
	*tcharStr = A2T(data);

	return tcharStr;
}
*/
