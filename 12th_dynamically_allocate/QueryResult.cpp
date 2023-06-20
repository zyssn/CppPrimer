#include "QueryResult.h"


ostream& myprint(ostream& out, const QueryResult& qr) { // ��һ���ǲ���IO   �ڶ������� ��ѯ��QueryResult����
    out << qr.sought << " occurs " << qr.lines->size() << ' ' << (qr.lines->size() > 1 ? "times" : "time")
        << endl;
    for (auto num : *(qr.lines)) { // �������  ���û���������  ������Ϊ��
        out << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << endl;  // ��ӡ�кź�
    }
    return out;
}

ostream& operator<<(ostream& out, const QueryResult& qr)
{
    // TODO: �ڴ˴����� return ���
    out << qr.sought << " occurs " << qr.lines->size() << ' ' << (qr.lines->size() > 1 ? "times" : "time")
        << endl;
    for (auto num : *(qr.lines)) { // �������  ���û���������  ������Ϊ��
        out << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << endl;  // ��ӡ�кź�
    }
    return out;
}
