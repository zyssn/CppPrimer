#pragma once
#include "../11th_associative_container/include.h"
#include "StrBlob.h"

using namespace std;


class StrBlob;
class StrBlobPtr
{
public:
    StrBlobPtr(StrBlob& a, size_t sz = 0);
    ~StrBlobPtr() {};
    string& deref() const;
    //ǰ�������
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    //���������
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    //�Ӽ�����
    StrBlobPtr& operator+(size_t n);
    StrBlobPtr& operator-(size_t n);
    StrBlobPtr& incr();
    friend bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs);

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

