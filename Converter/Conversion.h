#pragma once

#include <string>
namespace Converter
{
	class Conversion
	{
	public:
		Conversion();
		~Conversion();

		std::string ToString(int Value) const
		{
			return std::to_string(Value);
		}

		int ToInteger(std::string Value) const
		{
			return std::stoi(Value);
		}
	};
}
