#include "QueryResult.h"


ostream& myprint(ostream& out, const QueryResult& qr) { // ��һ���ǲ���IO   �ڶ������� ��ѯ��QueryResult����
    out << qr.sought << " occurs " << qr.lines->size() << ' ' << "times"
        << endl;
    for (auto num : *(qr.lines)) { // �������  ���û���������  ������Ϊ��
        out << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << endl;  // ��ӡ�кź�
    }
    return out;
}
