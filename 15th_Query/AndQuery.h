#pragma once
#include "../11th_associative_container/include.h"
#include "BinaryQuery.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {
		cout << "���� AndQuery ���캯��" << endl;
	}
	QueryResult eval(const TextQuery& t) const;
};

