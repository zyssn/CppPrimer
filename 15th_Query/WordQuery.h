#pragma once
#include "Query_base.h"
#include "Query.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"
#include "../11th_associative_container/include.h"

class WordQuery : public Query_base
{
	friend class Query;

	WordQuery(const string& s) : query_word(s) { cout << "调用 wordQuery 构造函数" << endl; }
	string rep() const override { return query_word; }
	QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }

	string query_word;
};

