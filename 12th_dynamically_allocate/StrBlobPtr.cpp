#include "StrBlobPtr.h"


StrBlobPtr::StrBlobPtr(StrBlob& a, size_t sz) : wptr(a.data), curr(sz) {}
std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "Dereference past the end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    curr++;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    check(curr, "increment past begin of StrBlobPtr");
    curr--;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --* this;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator+(size_t n)
{
    curr += n;
    check(curr, "impletment out of top range");
    return *this;
}

StrBlobPtr& StrBlobPtr::operator-(size_t n)
{
    curr -= n;
    check(curr, "impletment out of bottom range");
    return *this;
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "Increment past the end");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string& msg) const {
    auto p = wptr.lock();
    if (p) {
        if (p->size() > sz) {
            return p;
        }
        else {
            throw std::out_of_range(msg);
        }
    }
    else {
        throw std::runtime_error("unbound StrBlobPtr");
    }
}

bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    auto lp = lhs.wptr.lock(), rp = rhs.wptr.lock();
    if (lp == rp) {
        return (!lp || lhs.curr == rhs.curr);
    }
    else {
        return false;
    }
}
