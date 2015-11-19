// AddNumbers.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern "C" __declspec(dllexport) int addNumbers(int a, int b)
{
	return a + b;
}