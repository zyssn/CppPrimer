#pragma once
#include "../11th_associative_container/include.h"
#include "TextQuery.h"

using namespace std;

class QueryResult {
public:
    using line_no = vector<string>::size_type;
    friend ostream& myprint(ostream&, const QueryResult&); //不能用书上的print  不然运行不了
	friend ostream& operator<<(ostream&, const QueryResult&);
    //QueryRestlt(){}
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
        : sought(s), file(f), lines(p) { }   // 构造
	//返回指向保存行号的set的迭代器
	set<line_no>::iterator begin() const {
		return lines->begin();
	}
	set<line_no>::iterator end() const {
		return lines->end();
	}
	shared_ptr<vector<string>> get_file() const {
		return file;
	}

private:
    string sought;  // 查询的单词
    shared_ptr<vector<string>> file; // 读入文件
    shared_ptr<set<line_no>> lines; // 出现的行号 
};
