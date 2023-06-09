#pragma once
#include "../11th_associative_container/include.h"
#include "TextQuery.h"

using namespace std;

class QueryResult {
private:
    string sought;  // ��ѯ�ĵ���
    shared_ptr<vector<string>> file; // �����ļ�
    shared_ptr<set<unsigned int>> lines; // ���ֵ��к�
public:
    friend ostream& myprint(ostream&, const QueryResult&); //���������ϵ�print  ��Ȼ���в���
    //QueryRestlt(){}
    QueryResult(string s, shared_ptr<set<unsigned int>> p, shared_ptr<vector<string>> f)
        : sought(s), file(f), lines(p) { }   // ����
};
