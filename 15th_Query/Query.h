#pragma once
#include "../11th_associative_container/include.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"
#include "WordQuery.h"
#include "Query_base.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"

using namespace std;

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const string&);
	Query(const Query& q);
	QueryResult eval(const TextQuery& t) const { return q->eval(t); }
	string rep() const { return q->rep(); }

private:
	Query(shared_ptr<Query_base> query) : q(query) { cout << "调用 Query 构造函数" << endl; }
	shared_ptr<Query_base> q;
};

ostream& operator<<(ostream& os, const Query& query);
