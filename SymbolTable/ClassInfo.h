#pragma once

#include <vector>
#include <map>
#include "MethodInfo.h"
#include "VariableInfo.h"

namespace SymbolTable {

	class ClassInfo : public Symbol {
	public:
		ClassInfo( std::string _name, Position position );
		void AddMethodInfo( const std::string name, const MethodInfo & info );
		void AddVariableInfo( const std::string name, const VariableInfo * info );
		const VariableInfo& GetVariableInfo( const std::string name ) const;
		const MethodInfo& GetMethodInfo( const std::string name ) const;
		const std::vector<MethodInfo>& GetMethods() const;
		void addBlock( std::unordered_map<std::string, Symbol*> * block );
		std::vector<std::string> GetMethodName();
		std::vector<std::string>  GetVarsName();
		int GetMethodCount();
		int GetVarsCount();

	private:
		std::map<std::string, MethodInfo> methods;
		std::map<std::string, VariableInfo> variables;
		std::unordered_map<std::string, Symbol*> * block;
		Position position;
	};
}