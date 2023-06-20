#pragma once
#include "BinaryQuery.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"
#include "../11th_associative_container/include.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {
		cout << "调用 OrQuery 构造函数" << endl;
	}
	QueryResult eval(const TextQuery& t) const;
};

