#include "test.h"

int sz;

auto sl = [](const string& s)->bool {
    return s.size() == sz;
};

bool fun_sl(const string& s) {
    return s.size() == sz;
}

test1 &operator+(test1 &t1, test2& t2)


{
    t1.a = t1.a + t2.a;
    return t1;
}

test2 &operator+(test2& t2, test3& t3)
{
    t2.b = t2.b + t3.b;
    return t2;
}

void test(){
    ifThenElse<string> i(false, "right", "false");

    string str = i();

    cout << str << endl;
}

void testPrintString()
{
    printString ps;
    string str = ps();
    cout << str << endl;
}

void testaddVec()
{
    addVec adv;
    adv();

    adv.print();
}

void testLambda()
{
    vector<string> arr{ "abc", "a", "sd", "d", "f", "dg", "ter", "v" };
    
    function<bool(const string&)> f1 = stringLen();
    function<bool(const string&)> f2 = sl;
    function<bool(const string&)> f3 = fun_sl;

    for (int i = 1; i <= 3; ++i) {
        sz = i;
        int count = count_if(arr.begin(), arr.end(), f3);
        cout << "单词长度为 " << i << "的个数为" << count << "个。" << endl;
    }
}



