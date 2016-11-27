#pragma once

#include <vector>
#include <deque>
#include <list>
#include "FileSystemEntry.h"

// ein anderer Container
using FileSystemData = std::vector < FileSystemEntry > ;
//using FileSystemData = std::deque < FileSystemEntry > ;
//using FileSystemData = std::list < FileSystemEntry > ;

class UseContainer
{
public:
	static void BrowseFilesystem();

private:
	static void ListFiles(FileSystemData items);
	static void ListDirectories(FileSystemData items);
	static void CalculateSize(FileSystemData items);
	static void ListFileSystemMetrics(FileSystemData items);
	static void ListFilesGreater(FileSystemData items, long long size);
};

