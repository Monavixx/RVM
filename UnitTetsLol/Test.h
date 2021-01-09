#pragma once
#include <QtCore>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(lol)
    {
    public:
        TEST_METHOD(lolss)
        {
            Assert::IsTrue(true);
        }
    };
}