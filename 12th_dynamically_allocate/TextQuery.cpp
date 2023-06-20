#include "TextQuery.h"

TextQuery::TextQuery(ifstream& infile) : file(new vector<string>) {
    string tmp;
    while (getline(infile, tmp)) {  //�����ļ�  ��ÿһ��
        file->push_back(tmp);    // ���� vs
        int lineNo = (int)file->size() - 1; // ��ǰ�к�
        istringstream line(tmp); // ת��Ϊ is
        string word;
        while (line >> word) {  // is ������ ÿ������
            shared_ptr<set<line_no>>& lines = wm[word];  // ע�����Ǹ�ָ�룬Ҫnew���ٿռ�
            if (!lines) //  ����������û�еĻ�  Ϊ��  ��Ҫ���ٿռ�
                lines.reset(new set<line_no>);  //����һ���µ�set
            else
                lines->insert(lineNo); // ��set�в����к�
        }
    }
}

QueryResult TextQuery::query(const string& s) const {   //��ѯ����
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end()) { // ���û���ҵ�
        return QueryResult(s, nodata, file);
    }
    else { //  ����ҵ���
        return QueryResult(s, loc->second, file);
    }
}