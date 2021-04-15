#pragma once
#include "Namespace.h"

class NamespaceList : public std::unordered_map<String, Namespace*>
{
public:
	inline NamespaceList() {}
	inline NamespaceList(const std::unordered_map<String, Namespace*>& namespaceList) : std::unordered_map<String, Namespace*>(namespaceList) {}
	inline NamespaceList(const NamespaceList& namespaceList) : std::unordered_map<String, Namespace*>(namespaceList) {}

	inline void AddNamespace(Namespace* _namespace) { (*this)[_namespace->GetName()] = _namespace; }
	inline Namespace* GetNamespace(const String& name) {return (*this)[name]; }
};