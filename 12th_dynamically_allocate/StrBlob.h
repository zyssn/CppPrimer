#pragma once
#include "../11th_associative_container/include.h"
#include "StrBlobPtr.h"
using namespace std;

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    StrBlob(const StrBlob& obj)
        : data(new vector<string>(*obj.data)) {}
    StrBlob& operator=(const StrBlob& rhs) {
        auto p = rhs.data;
        data.reset();
        data = rhs.data;
        return *this;
    }
    ~StrBlob() {
        data.reset();
    }
    size_type size() { return data->size(); }
    const size_type size() const { return data->size(); }
    bool empty() { return data->empty(); }
    void push_back(const string& s) { data->push_back(s); }
    void push_back(string&& s) { data->push_back(move(s)); }
    void pop_back();
    size_t use_count();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string& msg) const;
};

