#include <cstring> 
#include <cassert>
#include <iostream>

#include <crtdbg.h>

namespace MyStringLib
{
	void strcpy(char* target, char* source)
	{
		for (; *target = *source; ++target, ++source); // classic C, nicht gut!!
	}
}

namespace MyLib = MyStringLib; // alias
using MyLib::strcpy; // das eigene strcpy

char** CopyArgs(int argc, char* argv[])
{
	auto buffer = new char*[argc];  // Puffer f�r alle Argumente
	for (int i = 0; i < argc; i++)
	{
		buffer[i] = new char[strlen(argv[i]) + 1]; // Puffer f�r das Argument + 0
		strcpy(buffer[i], argv[i]);
	}
	return buffer;
}

void deleteBuffer(int len, char** buffer)
{
	for (int i = 0; i < len; i++)
		delete[] buffer[i];
	delete[] buffer;
}

char** CopyEnv(char* envp[], int& len)
{
	len = 0;
	while (envp[len++]); // Eintr�ge z�hlen bis zum nullptr
	return CopyArgs(--len, envp); // nullptr eintrag von l�nge weg
}

void outBuffer(int argc, char** buffer)
{
	for (int i = 0; i < argc; ++i)
		std::cout << buffer[i] << std::endl;
}

int main(int argc, char* argv[], char* envp[])
{
	char** argCopy = CopyArgs(argc, argv);

	int len = 0;
	char** envCopy = CopyEnv(envp, len);

	outBuffer(argc, argCopy);
	outBuffer(len, envCopy);


	deleteBuffer(argc, argCopy);
	deleteBuffer(len, envCopy);

	assert(!_CrtDumpMemoryLeaks());
	assert(_CrtCheckMemory());
}