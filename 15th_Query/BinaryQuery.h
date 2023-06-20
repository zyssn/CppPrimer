#pragma once
#include "Query_base.h"
#include "Query.h"
#include "../11th_associative_container/include.h"

class BinaryQuery : public Query_base
{
protected:
	Query lhs;
	Query rhs;
	string opSym;
	BinaryQuery(const Query &l, const Query &r, string s):
		lhs(l), rhs(r), opSym(s) {
		cout << "调用 BinaryQuery 构造函数" << endl;
	}
	string rep() const { 
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; 
	}	
};

