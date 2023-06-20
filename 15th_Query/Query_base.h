#pragma once
#include "../11th_associative_container/include.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"
#include "Query.h"

using namespace std;

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery &text) const = 0;
	virtual string rep() const = 0;
};

