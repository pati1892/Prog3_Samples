#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <array>

using namespace std;

const char* FNAME = "Data.bin";
const int MaxValues = 100;

void WriteToFile()
{
	ofstream outfile(FNAME, ios::out | ios::binary);
	if (outfile)
	{
		for (int i = 0; i < MaxValues; i++)
		{
			try
			{
				int help = i * 10 + 1;
				outfile.write(reinterpret_cast<const char *>(&help), sizeof(int));
			}
			catch (...)
			{
				cerr << "could not write to " << FNAME << endl;
			}
		}
		outfile.close();
	}
	else
		cerr << "could not open " << FNAME << endl;
}

void ReadFromFile()
{
	ifstream infile(FNAME, ios::in, ios::binary);
	if (infile)
	{
		for (int i = 0; i < MaxValues; i += 10)
		{
			try
			{
				int help;
				infile.seekg(i * sizeof(int), ios::beg);
				infile.read(reinterpret_cast<char*>(&help), sizeof(int));
				cout << "Read Value" << setw(2) << i << "=" << help << endl;
			}
			catch (...)
			{
				cerr << "could not read from " << FNAME << endl;
			}
		}
		infile.close();
	}
	else
		cerr << "could not open " << FNAME << endl;
}

void KillFileIfExists(const char* name)
{
	try
	{
		std::tr2::sys::path myPath{ name };
		if (std::tr2::sys::exists(myPath))
			std::tr2::sys::remove(myPath);
	}
	catch (...)
	{
		cerr << "could not delete " << FNAME << endl;
	}
}

template<typename T, size_t len>
class ArrayToFile
{
public:
	ArrayToFile(string nameVal)
	{
		name = nameVal;
	}

	bool WriteToFile(array<T, len>& data)
	{
		auto writeResult = false;
		if (openFile(wrMode))
		{
			writeResult = writeData(data);
			closeFile();
		}
		return writeResult;
	}

	bool ReadFromFile(array<T, len>& data)
	{
		auto readResult = false;
		if (openFile(rdMode))
		{
			readResult = readData(data);
			closeFile();
		}
		return readResult;
	}

private:
	const static auto wrMode = ios::out | ios::in | ios::trunc;
	const static auto rdMode = ios::in;

	bool openFile(int mode) 
	{
		file.open(name.data(), mode);
		if (file.bad())
			return false;
		return true;
	}

	void closeFile() { file.close(); }

	bool writeData(array<T, len>& data)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			try
			{
				file << data[i] << endl;
			}
			catch (...)
			{
				return false;
			}
		}
		return true;
	}

	bool readData(array<T, len>& data)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			try
			{
				file >> data[i];
			}
			catch (...)
			{
				return false;
			}
		}
		return true;
	}

	fstream file;
	string name;
};

void UseClass()
{
	auto textFileName = "Data.txt";
	KillFileIfExists(textFileName);

	array<double, 10> data = { 1.1, 2, 3, 4, 5, 6, 7, 8, 9, 10.1 };
	ArrayToFile<double, 10> adapter(textFileName);
	auto result = adapter.WriteToFile(data);
	if (result)
	{
		array<double, 10> readData;
		if (!adapter.ReadFromFile(readData))
			cout << "read data failed\n";
		else
		{
			for (auto value : readData)
				cout << value << endl;
		}
	}
	else
		cout << "write data failed\n";
}

int main()
{
	KillFileIfExists(FNAME);
	WriteToFile();
	ReadFromFile();

	UseClass();
}
