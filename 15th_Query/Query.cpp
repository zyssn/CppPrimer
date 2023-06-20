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
    // TODO: 在此处插入 return 语句
    return os << query.rep() << endl;
}

Query::Query(const string& s) : q(new WordQuery(s)) {
    cout << "调用 Query 构造函数 " << endl; }

Query::Query(const Query& query): q(query.q)
{

}
