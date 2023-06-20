#include "NotQuery.h"

QueryResult NotQuery::eval(const TextQuery& t) const
{
    auto result = query.eval(t);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();

    for (size_t i = 0; i < sz; ++i) {
        if (beg == end || *beg != i) {
            ret_lines->insert(i);
        }
        else if (beg != end) ++beg;
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}
