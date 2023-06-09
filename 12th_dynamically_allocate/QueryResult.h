#pragma once
#include "../11th_associative_container/include.h"
#include "TextQuery.h"

using namespace std;

class QueryResult {
private:
    string sought;  // 查询的单词
    shared_ptr<vector<string>> file; // 读入文件
    shared_ptr<set<unsigned int>> lines; // 出现的行号
public:
    friend ostream& myprint(ostream&, const QueryResult&); //不能用书上的print  不然运行不了
    //QueryRestlt(){}
    QueryResult(string s, shared_ptr<set<unsigned int>> p, shared_ptr<vector<string>> f)
        : sought(s), file(f), lines(p) { }   // 构造
};
