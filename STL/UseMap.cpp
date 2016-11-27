#include <iostream>
#include <utility>

#include "UseMap.h"

UseMap::UseMap()
{
	MessageMap.insert({ "Case1", &UseMap::HandlerCase1 }); // Adresse in der Funktion in Klasse
	MessageMap.insert({ "Case2", &UseMap::HandlerCase2 });
	MessageMap.insert({ "Case3", &UseMap::HandlerCase3 });
}

UseMap::~UseMap()
{

}

void UseMap::HandlerCase1(const std::string info)
{
	std::cout << "HandlerCase01 " << info << "\n";
}

void UseMap::HandlerCase2(const std::string info)
{
	std::cout << "HandlerCase02 " << info << "\n";
}

void UseMap::HandlerCase3(const std::string info)
{
	std::cout << "HandlerCase03 " << info << "\n";
}

void UseMap::SwitchWithMap(const std::string aCase)
{
	auto result = MessageMap.find(aCase);
	if (result != MessageMap.end())
		(this->*result->second)(aCase); // Funktion der Klasse rufen
}
