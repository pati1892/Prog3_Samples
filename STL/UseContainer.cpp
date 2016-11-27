#include <filesystem>
#include <iostream>
#include <algorithm>
#include <functional>

#include "UseContainer.h"

namespace fs = std::experimental::filesystem::v1;

FileSystemData GetEntries(const fs::path& directory)
{
	auto endIter = fs::directory_iterator(); // Iterator für Verzeichnis

	FileSystemData items;
	for (auto dirIter = fs::directory_iterator(directory); dirIter != endIter; ++dirIter)
	{
		const fs::directory_entry& entry = *dirIter;
		fs::path current = entry.path();
		auto isDir = fs::is_directory(entry.status());
		auto size = (isDir) ? 0 : fs::file_size(current);
		FileSystemEntry data(current.string(), size, isDir);
		items.push_back(data);
		if (data.getDir())
		{
			auto subDir = GetEntries(current);
			std::for_each(subDir.begin(), subDir.end(), 
				[&items](FileSystemEntry& item){ items.push_back(item); });
		}
	}
	return items;
}

void UseContainer::BrowseFilesystem()
{
	auto currentDirectory = fs::current_path();
	std::cout << "current directory = " << currentDirectory.string() << std::endl;

	FileSystemData items = GetEntries(currentDirectory);

	ListFiles(items);
	ListDirectories(items);
	CalculateSize(items);
	ListFileSystemMetrics(items);
	ListFilesGreater(items, 10000);
	
}

void UseContainer::ListFiles(FileSystemData items)
{
	std::cout << "*** all files " << std::endl;
	std::for_each(items.cbegin(), items.cend(), 
		[](const FileSystemEntry& item) {  // lambda für STL Funktion, modern
		if (item.getDir())
			return;
		std::cout << item.getName() << std::endl;
	});
}

class DirectoryOp // Funktionsobjekt für Verzeichnisse, classic STL
{
public:
	void operator()(const FileSystemEntry& item) const
	{
		if (item.getDir())
			std::cout << item.getName() << std::endl;
	}
};

void UseContainer::ListDirectories(FileSystemData items)
{
	std::cout << "*** all directories " << std::endl;
	std::for_each(items.cbegin(), items.cend(), DirectoryOp()); // Funktor, class STL
}

void UseContainer::CalculateSize(FileSystemData items)
{
	long long fullSize = 0;
	for (auto item : items) // range based loop
		fullSize += item.getSize();
	std::cout << "*** full size is = " << fullSize << " bytes\n";
}

void UseContainer::ListFileSystemMetrics(FileSystemData items)
{
	std::cout << "*** metrics " << std::endl;

	auto amount = std::count_if(items.cbegin(), items.cend(), 
		[](const FileSystemEntry& item)->bool{ return !item.getDir(); });
	std::cout << "files in browse = " << amount << std::endl;

	amount = std::count_if(items.cbegin(), items.cend(), 
		[](const FileSystemEntry& item)->bool{ return item.getDir(); });
	std::cout << "directories in browse = " << amount << std::endl;

	long long sum = 0;
	long count = 0;
	std::for_each(items.cbegin(), items.cend(), 
		[&sum, &count](const FileSystemEntry& item){ sum += item.getSize(); ++count; });
	std::cout << "average size = " << static_cast<double>(sum) / count << " bytes\n";
}

class FileSystemEntryGreater : public std::binary_function < FileSystemEntry, long long, bool >
{
public:
	bool operator()(const FileSystemEntry& item, const long long& size) const
	{
		return item.getSize() > size;
	}
};

void UseContainer::ListFilesGreater(FileSystemData items, long long size)
{
	std::cout << "*** files greater size > " << size << " bytes\n";

	FileSystemData result(items.size());
	auto copyEnd =
		//std::copy_if(items.cbegin(), items.cend(), result.begin(), 
		//	std::bind2nd(FileSystemEntryGreater(), size));
		std::copy_if(items.cbegin(), items.cend(), result.begin(),
			std::bind([](const auto &item, const auto& size) {return item.getSize() > size; }, std::placeholders::_1, size));
	result.erase(copyEnd, result.end());
	for (auto item : result)
		std::cout << item.getName() << " greater " << size << " Bytes\n";
}

