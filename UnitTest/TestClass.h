#pragma once
#include <QtCore>
#include "CppUnitTest.h"
#include "../RelaxVM/Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(TestClass)
    {
    public:
        TEST_METHOD(TestGetters_1)
        {
            QString name = "TestClass";
            MethodSignature ms1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature ms2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(ms1),
                Method(ms2, AccessModifier::PUBLIC, true)
            };
            Class myClass(name, methods);

            
            QString getName = myClass.GetName();
            QList<Method> getMethods = myClass.GetMethods();


            Assert::AreEqual(getName.toStdString().c_str(), name.toStdString().c_str());
            Assert::IsTrue(methods == getMethods);
        }
    };
}