#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <array>
using namespace std;

#include <memory> // Schritt2
namespace ToTest
{

	// Schritt 1 nach Schritt 2 = redesign für Test

	class InnerProcessor
	{
	public:
		//int MultiplyByThree(int Input) // Schritt 1
		virtual int MultiplyByThree(int Input) // Schritt 2
		{
			return Input * 3;
		}
	};

	class MultiProcessor
	{
	public:
		//MultiProcessor() {} // Schritt 1
		MultiProcessor() { pused = &used; } // Schritt 2
		MultiProcessor(InnerProcessor& used) : pused(&used) { } // Schritt 2 dependency injection

		int MultiplyWithInner(int Input)
		{
			//return used.MultiplyByThree(Input) * 3; // Schritt 1
			return pused->MultiplyByThree(Input) * 3; // Schritt 2
		}

	private:
		InnerProcessor used; // Schritt 1
		InnerProcessor* pused; // Schritt 2
	};

}

using namespace ToTest;

namespace MockUnitTest
{		
	TEST_CLASS(MockTest)
	{
	public:
		
		TEST_METHOD(MultiplyWithInnerIsValue) // integration test
		{
			MultiProcessor instance;
			const int len = 5;
			array<int, len> input = { -1, 0, 1, 3, 9 };
			array<int, len> result = {-9, 0, 9, 27, 81}; // schwierig, da used object auf das Ergebnis Auswirkung hat
			for (int i = 0; i < len; ++i)
				Assert::AreEqual(result[i], instance.MultiplyWithInner(input[i]));
		}

		// Mock für innere Klasse
		class InnerProcessorStub : public InnerProcessor // Liskov Prinzip
		{
		public:
			virtual int MultiplyByThree(int Input) override // Schritt 2
			{
				return 1;
			}
		};

		TEST_METHOD(MultiplyWithInnerStubIsValue) // mock unit test
		{
			MultiProcessor instance{ InnerProcessorStub() };
			const int len = 5;
			array<int, len> input = { -1, 0, 1, 3, 9 };
			array<int, len> result = { 3, 3, 3, 3, 3 }; // Ergebnis nur von eigener Klasse, test mit einer Zahl reicht
			for (int i = 0; i < len; ++i)
				Assert::AreEqual(result[i], instance.MultiplyWithInner(input[i]));
		}


	};
}