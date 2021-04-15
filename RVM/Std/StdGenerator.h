#pragma once
#include "Classes/CustomObject.h"
#include "Classes/RelaxArray.h"
#include "Classes/RelaxConsole.h"
#include "Classes/RelaxConverter.h"
#include "Classes/RelaxPointer.h"
#include "Classes/RelaxFile.h"
#include "Classes/RelaxRandom.h"

class StdGenerator
{
public:
	static void GenerateNamespaces()
	{
		relax = new Namespace("Relax");
		GlobalVariables::namespaces.AddNamespace(relax);
	}

	static void GenerateClasses()
	{
		RelaxConsole::GenerateMetaClass();
		RelaxArray::GenerateMetaClass();
		RelaxRandom::GenerateMetaClass();
		RelaxConverter::GenerateMetaClass();
		Object::GenerateMetaClass();
		RelaxFile::GenerateMetaClass();

		relax->AddClass(RelaxConsole::metaClass);
		relax->AddClass(RelaxArray::metaClass);
		relax->AddClass(RelaxRandom::metaClass);
		relax->AddClass(RelaxConverter::metaClass);
		relax->AddClass(Object::metaClass);
		relax->AddClass(RelaxFile::metaClass);
	}

	static void GenerateMethods()
	{
		RelaxConsole::GenerateMetaMethods();
		RelaxArray::GenerateMetaMethods();
		RelaxRandom::GenerateMetaMethods();
		RelaxConverter::GenerateMetaMethods();
		Object::GenerateMetaMethods();
		RelaxFile::GenerateMetaMethods();
	}

	static inline Namespace* relax = nullptr;
};

