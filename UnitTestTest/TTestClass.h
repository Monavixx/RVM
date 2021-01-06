#pragma once
#include <QtCore>
#include "CppUnitTest.h"
#include "../RelaxVM/Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTest
{
    TEST_CLASS(TestClass)
    {
    public:
        TEST_METHOD(testik)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2,{}, AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);


            QString getName = testingClass.GetName();
            QList<Method> getMethods = testingClass.GetMethods();


            Assert::IsTrue(getName == name);
            Assert::IsTrue(getMethods == methods);
        }
    };
}