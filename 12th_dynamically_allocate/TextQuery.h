#pragma once
#include "../11th_associative_container/include.h"
#include "QueryResult.h"
using namespace std;

class QueryResult;
class TextQuery {
private:
    shared_ptr<vector<string>> file;  //  ���ڽ��մ�����ļ� ��ÿһ���ַ���
    map<string, shared_ptr<set<unsigned int>>>  wm; // ÿ������ӳ�䵽��Ӧ���к�
public:
    // TextQuery(){ };
    TextQuery(ifstream& infile); //   ���캯��
    QueryResult query(const string&);  // ��ѯ
};

