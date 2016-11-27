#include <iostream>
#include <chrono>

using namespace std; // Namensraum implizit anwenden

void newInC1x()
{
	using namespace std::literals;
	std::chrono::milliseconds msec(1s); // s, ms, h, etc.
	std::cout << "msec=" << msec.count() << "\n";

	auto milValue = 1'000'000; // zur besseren Lesbarkeit 
	std::cout << "milValue=" << milValue << "\n";
}

int main()
{
	// integer
	int Decimal = 12;
	int Octal = 012;
	long Hexadecimal = 0x12l; // long value

	cout << "Dec=" << Decimal << "\n"
		<< "Oct=" << Octal << "\n"
		<< "Hex=" << Hexadecimal << "\n";

	// real numbers
	float SinglePrec = 12.3f;
	double DoublePrec = 12.3;
	double ExDoublePrec = 1.23e1l;

	cout << "Single=" << SinglePrec << "\n"
		<< "Double=" << DoublePrec << "\n"
		<< "ExDouble=" << ExDoublePrec << "\n";

	// characters
	char cA = 'A';
	char c1 = static_cast<char>('\0x31');
	char CR = '\n';  // ein Steuerzeichen

	cout << cA << c1 << CR; // A1 und Zeilenvorschub

	// strings
	const char *Text = "This is a text literal in C++\n";
	const char *SubText = "This is terminated\0bevor the end";

	cout << Text;
	cout << SubText << endl;

	newInC1x();
}