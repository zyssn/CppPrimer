#include "Query.h"

Query operator~(const Query& operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator|(const Query &l, const Query &r)
{
    return shared_ptr<Query_base>(new OrQuery(l, r));
}

Query operator&(const Query& l, const Query& r)
{
    return shared_ptr<Query_base>(new AndQuery(l, r));
}

ostream& operator<<(ostream& os, const Query& query)
{
    // TODO: �ڴ˴����� return ���
    return os << query.rep() << endl;
}

Query::Query(const string& s) : q(new WordQuery(s)) {
    cout << "���� Query ���캯�� " << endl; }

Query::Query(const Query& query): q(query.q)
{

}
