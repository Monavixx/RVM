#pragma once
#include <QtCore>
#include "CppUnitTest.h"
#include "../RelaxVM/MethodSignature.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(TestMethodSignature)
    {
    public:
        TEST_METHOD(Test_ToString_1)
        {
            QString name = "Sum";
            QString dataType = "Relax.Int64";
            QString className = "Relax.Math";
            QList<Parameter> parameters = {
                Parameter("First", "Relax.Int64"),
                Parameter("Second", "Relax.Int64")
            };

            MethodSignature methodSignature(name, dataType, className, parameters);
            Assert::AreEqual(methodSignature.ToString().toStdString().c_str(), "Relax.Int64 Relax.Math.Sum(Relax.Int64,Relax.Int64)");
        }
        TEST_METHOD(Test_ToString_2)
        {
            QString name = "MyMethod";
            QString dataType = "Relax.String";
            QString className = "MyClass";
            QList<Parameter> parameters = {
                Parameter("First", "Relax.String"),
                Parameter("Second", "Relax.Float")
            };

            MethodSignature methodSignature(name, dataType, className, parameters);
            Assert::AreEqual(methodSignature.ToString().toStdString().c_str(), "Relax.String MyClass.MyMethod(Relax.String,Relax.Float)");
        }
        TEST_METHOD(Test_Getters)
        {
            QString name = "Sum";
            QString dataType = "Relax.Int64";
            QString className = "Relax.Math";
            QList<Parameter> parameters = {
                Parameter("First", "Relax.Int64"),
                Parameter("Second", "Relax.Int64")
            };

            MethodSignature methodSignature(name, dataType, className, parameters);

            Assert::AreEqual(methodSignature.GetName().toStdString().c_str(), "Sum");
            Assert::AreEqual(methodSignature.GetDataType().toStdString().c_str(), "Relax.Int64");
            Assert::AreEqual(methodSignature.GetNameClass().toStdString().c_str(), "Relax.Math");
            Assert::IsTrue(methodSignature.GetParameters() == QList{ Parameter("First", "Relax.Int64"),Parameter("Second", "Relax.Int64") });
        }
        TEST_METHOD(Test_Setters)
        {
            QString name = "Sum";
            QString dataType = "Relax.Int64";
            QString className = "Relax.Math";
            QList<Parameter> parameters = {
                Parameter("First", "Relax.Int64"),
                Parameter("Second", "Relax.Int64")
            };

            MethodSignature methodSignature(name, dataType, className, parameters);

            methodSignature.SetName("UpdatedSum");
            methodSignature.SetDataType("UpdatedRelax.Int64");
            methodSignature.SetNameClass("UpdatedRelax.Math");
            methodSignature.SetParameters({ Parameter("First", "Relax.Int64"),Parameter("Second", "UpdateRelax.Int64"),Parameter("Test145___Fk", "MyDataType") });

            Assert::AreEqual(methodSignature.GetName().toStdString().c_str(), "UpdatedSum");
            Assert::AreEqual(methodSignature.GetDataType().toStdString().c_str(), "UpdatedRelax.Int64");
            Assert::AreEqual(methodSignature.GetNameClass().toStdString().c_str(), "UpdatedRelax.Math");
            Assert::IsTrue(methodSignature.GetParameters() == QList{ Parameter("First", "Relax.Int64"),Parameter("Second", "UpdateRelax.Int64"),Parameter("Test145___Fk", "MyDataType") });
        }
        TEST_METHOD(Test_AddParameter)
        {
            QString name = "Sum";
            QString dataType = "Relax.Int64";
            QString className = "Relax.Math";
            QList<Parameter> parameters = {
                Parameter("First", "Relax.Int64"),
                Parameter("Second", "Relax.Int64")
            };

            MethodSignature methodSignature(name, dataType, className, parameters);

            methodSignature.AddParameter(Parameter("TestDataType", "testName"));

            Assert::IsTrue(methodSignature.GetParameters() == QList{ Parameter("First", "Relax.Int64"),Parameter("Second", "Relax.Int64"),Parameter("TestDataType", "testName") });
        }

    };
}