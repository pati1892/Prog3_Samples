#pragma once
#include <map>
#include <string>


class UseMap
{
public:
	UseMap();
	~UseMap();

	void SwitchWithMap(const std::string aCase);

private:
	void HandlerCase1(const std::string info);
	void HandlerCase2(const std::string info);
	void HandlerCase3(const std::string info);

	using Handler = void (UseMap::*)(const std::string info);

	using CaseMap = std::map < std::string, Handler >;

	CaseMap MessageMap;

};

