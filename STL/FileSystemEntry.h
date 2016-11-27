#pragma once
#include <string>

class FileSystemEntry // ein Eintrag im Dateisystem
{
public:
	FileSystemEntry();
	FileSystemEntry(const std::string Name, const long long Size, const bool dirFlag);
	~FileSystemEntry();

	std::string getName() const { return Name; } 
	void setName(const std::string Name);
	long long getSize() const { return Size; } 
	void setSize(const long long Size);
	bool getDir() const { return dirFlag;  }
	void setDir(bool dirFlag);
private:
	std::string Name; // gesamter Name
	long long Size; // größe des Dateisystemelements
	bool dirFlag; // ist Directory
};

