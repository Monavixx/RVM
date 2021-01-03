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
        TEST_METHOD(Test_Getters)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            QByteArray code = {};
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;


            Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);


            Assert::IsTrue(method.GetAccessModifier() == accessModifier);
            Assert::AreEqual(method.IsStatic(), isStatic);
        }
        TEST_METHOD(Test_Setters)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            QByteArray code = {};
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;
            Method method(name, dataType, nameClass, parameters,code, accessModifier, isStatic);
            

            isStatic = false;
            accessModifier = AccessModifier::PROTECTED;
            method.SetIsStatic(isStatic);
            method.SetAccessModifier(accessModifier);


            Assert::IsTrue(method.GetAccessModifier() == accessModifier);
            Assert::AreEqual(method.IsStatic(), isStatic);
        }
        TEST_METHOD(Test_OperatorEqualTo_1)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            QByteArray code = {};
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;
            Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);
            Method method2(name, dataType, nameClass, parameters, code, accessModifier, isStatic);
            

            bool result = method == method2;


            Assert::IsTrue(result);
        }
        TEST_METHOD(Test_OperatorEqualTo_2)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            QByteArray code = {};
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;
            Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);
            Method method2("newName", dataType, nameClass, parameters, code,accessModifier, isStatic);


            bool result = method == method2;


            Assert::IsFalse(result);
        }
        TEST_METHOD(Test_OperatorEqualTo_3)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            QByteArray code = {};
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;
            Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);
            Method method2(name, dataType, nameClass, parameters, code, accessModifier, false);


            bool result = method == method2;


            Assert::IsFalse(result);
        }
        TEST_METHOD(Test_OperatorEqualTo_4)
        {
            QString name = "MyPrint";
            QString dataType = "void";
            QString nameClass = "Test";
            QList<Parameter> parameters = {
                Parameter("text", "Relax.String")
            };
            QByteArray code = {};
            bool isStatic = true;
            AccessModifier accessModifier = AccessModifier::PUBLIC;
            Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);
            Method method2(name, dataType, nameClass, {}, code, accessModifier, isStatic);


            bool result = method == method2;


            Assert::IsFalse(result);
        }
    };
}