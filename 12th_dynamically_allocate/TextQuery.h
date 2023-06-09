#pragma once
#include "../11th_associative_container/include.h"
#include "QueryResult.h"
using namespace std;

class QueryResult;
class TextQuery {
private:
    shared_ptr<vector<string>> file;  //  用于接收传入的文件 的每一行字符串
    map<string, shared_ptr<set<unsigned int>>>  wm; // 每个单词映射到对应的行号
public:
    // TextQuery(){ };
    TextQuery(ifstream& infile); //   构造函数
    QueryResult query(const string&);  // 查询
};

