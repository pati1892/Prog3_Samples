#pragma once
#include <cstring>

// Funktionstemplate für Maximum
template<class T> // generischer Typ T
T maximum(T a, T b) { return a > b ? a : b; }

// Spezialiserung für const char*
template<> // kein generischer Typ
const char* maximum(const char* a, const char* b)
{
	// c String Bibliothek
	auto result = strcmp(a, b); // -1 = a < b, 0 = a == b; 1 = a > b
	return (result > 0) ? a : b;
}
