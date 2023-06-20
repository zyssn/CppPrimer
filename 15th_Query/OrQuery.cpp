#include "OrQuery.h"

QueryResult OrQuery::eval(const TextQuery& t) const
{
    auto right = rhs.eval(t), left = lhs.eval(t);
    
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}
