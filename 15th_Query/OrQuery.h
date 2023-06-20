#pragma once
#include "BinaryQuery.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"
#include "../11th_associative_container/include.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {
		cout << "���� OrQuery ���캯��" << endl;
	}
	QueryResult eval(const TextQuery& t) const;
};

