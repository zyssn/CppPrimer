#include "Strvec.h"

allocator<string> Strvec::alloc;

Strvec::Strvec(const Strvec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    element = newdata.first;
    first_free = cap =  newdata.second;
}

Strvec& Strvec::operator=(const Strvec& s)
{
    auto data = alloc_n_copy(s.end() , s.begin());
    free();
    element = data.first;
    first_free = cap = data.second;
    return *this;
}

// 移动构造函数参数必须是可修改的右值
Strvec& Strvec::operator=(Strvec&& s) noexcept {
    // 必须进行自我赋值自检，否则会清空当前数据，造成内存泄漏
    if (&s != this) {
        free();
        element = s.element;
        first_free = s.first_free;
        cap = s.cap;

        s.element = s.first_free = s.cap = nullptr;
    }
    return *this;
}

Strvec::~Strvec()
{
    free();
}


void Strvec::reserve(size_t len) {
    if (len <= size()) return;
    size_t tmp = min(len, capacity()) - size();
    while (tmp) {
        push_back("");
        tmp--;
    }
}

void Strvec::resize(size_t len, string str) {
    if (len > capacity()) {
        free();         //释放原内存
        auto newdata = alloc.allocate(len);
        element = first_free = newdata;

        while (len--) {
            alloc.construct(first_free++, str);
        }
        
        cap = first_free;
        return;
    }

    auto p = element;
    size_t n = len;
    while (n) {
        alloc.construct(p++, str);
        n--;
    }
    if (len <= size()) {
        while (first_free != p) {
            alloc.destroy(--first_free);
        }
    }

}

void Strvec::push_back(const string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> Strvec::alloc_n_copy(const string* b, const string* e)
{
    auto data = alloc.allocate(e - b);
    cout << "copying..." << endl;
    return { data, uninitialized_copy(b, e, data) };
}

void Strvec::free()
{
    if (element) {
        for (auto p = first_free; p != element;)
            alloc.destroy(--p);
        alloc.deallocate(element, cap - element);
    }
}

Strvec::Strvec(Strvec&& s) noexcept : element(s.element), first_free(s.first_free), cap(s.cap) {
    cout << "moving ..." << endl;
    s.element = s.first_free = s.cap = nullptr;
}


void Strvec::reallocate()
{
    cout << "reallocating..." << endl;
    size_t newcapacity = size() ? 2 * size() : 1;

    // 拷贝原数据申请空间，浪费内存资源
    /*auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = element;

    while (elem != first_free) {
        alloc.construct(dest++, std::move(*elem++));
    }*/

    // 使用移动操作，
    auto newdata = alloc.allocate(newcapacity);
    auto dest = uninitialized_copy(make_move_iterator(begin()),
        make_move_iterator(end()), newdata);

    free();         //释放原内存
    element = newdata;
    first_free = dest;
    cap = element + newcapacity;
}

void testStrvec()
{
    Strvec s;
    vector<string> arr{ "hello", "world!", "Mr. ", "Mary", "thank", "you"};
    for (string str : arr) {
        s.push_back(str);
    }

    s.reserve(9);
    s.reserve(7);
    s.resize(18, "abc");


    Strvec ss(std::move(s));
    Strvec sss = std::move(ss);

    return;
}


