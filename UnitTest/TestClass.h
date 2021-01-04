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
        TEST_METHOD(Test_Getters)
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
        TEST_METHOD(Test_GetMethod)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2,{}, AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);

            Method* getMethod = testingClass.GetMethod(methodSignature1);

            Assert::IsTrue(*getMethod == methods[0]);
        }
        TEST_METHOD(Test_Setters)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2, {},AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);


            testingClass.SetName(name = "NewName");
            testingClass.SetMethods(methods = {
                Method(methodSignature2, {},AccessModifier::PROTECTED, true)
            });
            QString getName = testingClass.GetName();
            QList<Method> getMethods = testingClass.GetMethods();


            Assert::IsTrue(getName == name);
            Assert::IsTrue(getMethods == methods);
        }
        TEST_METHOD(Test_SetMethod)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2,{}, AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);
            int testingIndex = 1;
            Method newMethod = Method("NewMethod", "DataTypeMethod", name, {}, {}, AccessModifier::PROTECTED);


            testingClass.SetMethod(testingIndex, newMethod);
            methods = testingClass.GetMethods();


            Assert::IsTrue(newMethod == methods[testingIndex]);
        }
        TEST_METHOD(Test_AddMethod)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2,{}, AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);
            int testingIndex = 1;
            Method newMethod = Method("NewMethod", "DataTypeMethod", name, {}, {}, AccessModifier::PROTECTED);
            QList<Method> newMethodList = QList{
                Method(methodSignature1),
                Method(methodSignature2,{}, AccessModifier::PUBLIC, true),
                newMethod
            };


            testingClass.AddMethod(newMethod);


            Assert::IsTrue(testingClass.GetMethods() == newMethodList);
        }
        TEST_METHOD(Test_OperatorEqualTo_1)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2, {},AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);
            Class testingClass2(name, methods);


            bool result = testingClass == testingClass2;


            Assert::IsTrue(result);
        }
        TEST_METHOD(Test_OperatorEqualTo_2)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2,{}, AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);
            Class testingClass2("newName", methods);


            bool result = testingClass == testingClass2;


            Assert::IsFalse(result);
        }
        TEST_METHOD(Test_OperatorEqualTo_3)
        {
            QString name = "TestClass";
            MethodSignature methodSignature1("NameMethod", "DataTypeMethod", name, {});
            MethodSignature methodSignature2("NameMethod2", "DataTypeMethod2", name, {});
            QList<Method> methods = {
                Method(methodSignature1),
                Method(methodSignature2,{}, AccessModifier::PUBLIC, true)
            };
            Class testingClass(name, methods);
            methods[0].SetName("newNameMethod");
            Class testingClass2(name, methods);


            bool result = testingClass == testingClass2;


            Assert::IsFalse(result);
        }
    };
}