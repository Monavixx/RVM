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
        TEST_METHOD(TestToString_1)
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
        TEST_METHOD(TestToString_2)
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

        TEST_METHOD(TestGetters_1)
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
        TEST_METHOD(TestGetters_2)
        {
            QString name = "Unuineuh787877g7__nui";
            QString dataType = "GFRnfgruienvnf44";
            QString className = "HHhh78G2";
            QList<Parameter> parameters = {
                Parameter("__1__", "Fffff3"),
                Parameter("____2____", "TeEEeEe__78hj")
            };

            MethodSignature methodSignature(name, dataType, className, parameters);

            Assert::AreEqual(methodSignature.GetName().toStdString().c_str(), "Unuineuh787877g7__nui");
            Assert::AreEqual(methodSignature.GetDataType().toStdString().c_str(), "GFRnfgruienvnf44");
            Assert::AreEqual(methodSignature.GetNameClass().toStdString().c_str(), "HHhh78G2");
            Assert::IsTrue(methodSignature.GetParameters() == QList{ Parameter("__1__", "Fffff3"), Parameter("____2____", "TeEEeEe__78hj") });
        }
        TEST_METHOD(TestSetters_1)
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

        TEST_METHOD(TestAddParameter_1)
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