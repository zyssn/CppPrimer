#pragma once
#include "../11th_associative_container/include.h"
#include "QueryResult.h"
using namespace std;

class QueryResult;
class TextQuery {

public:
    // TextQuery(){ };
    using line_no = vector<string>::size_type;
    TextQuery(ifstream& infile); //   构造函数
    QueryResult query(const string&) const;  // 查询

private:
    shared_ptr<vector<string>> file;  //  用于接收传入的文件 的每一行字符串
    map<string, shared_ptr<set<line_no>>>  wm; // 每个单词映射到对应的行号
};

