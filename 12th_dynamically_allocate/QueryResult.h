#pragma once
#include "../11th_associative_container/include.h"
#include "TextQuery.h"

using namespace std;

class QueryResult {
public:
    using line_no = vector<string>::size_type;
    friend ostream& myprint(ostream&, const QueryResult&); //���������ϵ�print  ��Ȼ���в���
	friend ostream& operator<<(ostream&, const QueryResult&);
    //QueryRestlt(){}
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
        : sought(s), file(f), lines(p) { }   // ����
	//����ָ�򱣴��кŵ�set�ĵ�����
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
    string sought;  // ��ѯ�ĵ���
    shared_ptr<vector<string>> file; // �����ļ�
    shared_ptr<set<line_no>> lines; // ���ֵ��к� 
};
