#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication1\AnatarClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* name = "Lox";
			AnatarClass ac(name);
			Assert::AreEqual(name, ac.GetName());
		}
	};
}
