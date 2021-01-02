#pragma once
#include <QtCore>
#include "CppUnitTest.h"
#include "../RelaxVM/Method.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(TestMethod)
    {
    public:
        TEST_METHOD(TestGetters_1)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;

            Method method(name, dataType, nameClass, parameters, accessModifier, isStatic);

            Assert::IsTrue(method.GetAccessModifier() == accessModifier);
            Assert::AreEqual(method.IsStatic(), isStatic);
        }

        TEST_METHOD(TestSetters_1)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;

            Method method(name, dataType, nameClass, parameters, accessModifier, isStatic);

            Assert::IsTrue(method.GetAccessModifier() == accessModifier);
            Assert::AreEqual(method.IsStatic(), isStatic);

            isStatic = false;
            accessModifier = AccessModifier::PROTECTED;

            method.SetIsStatic(isStatic);
            method.SetAccessModifier(accessModifier);

            Assert::IsTrue(method.GetAccessModifier() == accessModifier);
            Assert::AreEqual(method.IsStatic(), isStatic);
        }
    };
}