#pragma once
#include "../11th_associative_container/include.h"
#include "QueryResult.h"
using namespace std;

class QueryResult;
class TextQuery {

public:
    // TextQuery(){ };
    using line_no = vector<string>::size_type;
    TextQuery(ifstream& infile); //   ���캯��
    QueryResult query(const string&) const;  // ��ѯ

private:
    shared_ptr<vector<string>> file;  //  ���ڽ��մ�����ļ� ��ÿһ���ַ���
    map<string, shared_ptr<set<line_no>>>  wm; // ÿ������ӳ�䵽��Ӧ���к�
};

