#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <memory>
#include <array>
using namespace std;

#include "../Converter/Conversion.h"
/*
#include <string>
namespace Converter
{
	class Conversion
	{
	public:
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
*/
using namespace Converter;

namespace ConverterUnitTest
{		
	TEST_CLASS(ConverterTest)
	{
	public:

		using ConversionPtr = unique_ptr < Conversion > ;
		ConversionPtr instance{ nullptr };

		TEST_METHOD_INITIALIZE(TestInitialize)
		{
			//ConversionPtr tmp{ new Conversion() };
			//instance.swap(tmp);
			instance.reset(new Conversion());
		}

		TEST_METHOD_CLEANUP(TestCleanup)
		{
			instance.reset();
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TextToIntegerConversion)
			TEST_DESCRIPTION(L"test conversion from integer values to text")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(IntegerToTextConversion)
		{
			const int len = 5;
			array<int, len> toConvert = { -100, 0, 1, 27, 9999 };
			array<string, len> expected = { string("-100"), string("0"), string("1"), string("27"), string("9999") };
			for (int i = 0; i < len; ++i)
			{
				auto result = instance->ToString(toConvert[i]);
				Assert::AreEqual(expected[i], result);
			}
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(IntegerToTextConversion)
			TEST_DESCRIPTION(L"test conversion from text string to integer values")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(TextToIntegerConversion)
		{
			const int len = 5;
			array<int, len> expected = { -100, 0, 1, 27, 9999 };
			array<string, len> toConvert = { string("-100"), string("0"), string("1"), string("27"), string("9999") };
			for (int i = 0; i < len; ++i)
			{
				auto result = instance->ToInteger(toConvert[i]);
				Assert::AreEqual(expected[i], result);
			}
		}

	};
}