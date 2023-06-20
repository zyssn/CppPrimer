#pragma once
#include "Query_base.h"
#include "Query.h"
#include "WordQuery.h"
#include "../11th_associative_container/include.h"

class NotQuery : public Query_base
{
	friend Query operator~(const Query& t);
	NotQuery(const Query& q) : query(q) { cout << "���� NotQuery ���캯��" << endl; }
	string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery& t) const;

	Query query;
};

