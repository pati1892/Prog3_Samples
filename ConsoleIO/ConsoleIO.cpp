#include <iostream> // c++ streams

int main() 
{
	std::cout << "An die Konsole" << std::endl;	// Text auf Konsole ausgeben und einen Zeilenvorschub anfügen
	std::cout << "Bitte eine Zahl Eingeben :";	// Text ohne Zeilenvorschub ausgeben
	int number;									// einen Ganzzahlwert anlegen
	std::cin >> number;							// den Wert von der Konsole lesen
	std::cout << "Die Eingabe war "				// den Wert mit Text ausgeben
		<< number << std::endl;				
}