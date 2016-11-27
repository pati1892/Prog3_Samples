#include "FileSystemEntry.h"


FileSystemEntry::FileSystemEntry() : Size(0), dirFlag(false)
{
}

FileSystemEntry::FileSystemEntry(const std::string Name, const long long Size, const bool dirFlag) 
	: Name(Name), Size(Size), dirFlag(dirFlag)
{
}

FileSystemEntry::~FileSystemEntry()
{
}

void FileSystemEntry::setName(const std::string Name)
{
	this->Name = Name;
}

void FileSystemEntry::setSize(const long long Size)
{
	this->Size = Size;
}

void FileSystemEntry::setDir(bool dirFlag)
{
	this->dirFlag = dirFlag;
}
