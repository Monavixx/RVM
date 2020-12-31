#pragma once
#include <QtCore>
#include "CppUnitTest.h"

#include "../RelaxVM/Program.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(TestProgram)
    {
    public:
        TEST_METHOD(TestIsLaunch_1)
        {
            const int amountArguments = 2;
            char* arguments[amountArguments] = {"RelaxVM.exe", "test.re"};
            Program program(amountArguments, arguments);
            Assert::IsTrue(program.IsLaunch());
        }
        TEST_METHOD(TestIsLaunch_2)
        {
            const int amountArguments = 2;
            char* arguments[amountArguments] = { "RelaxVM.exe", "-help" };
            Program program(amountArguments, arguments);
            Assert::IsFalse(program.IsLaunch());
        }
    };
}