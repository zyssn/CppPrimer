#include "Foo.h"

Foo Foo::sorted()&&
{
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const&
{
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}

void Foo::fooPrint()
{
    int index = 1;
    for (auto num : data) {
        cout << num << " ";
        if (index++ % 20 == 0) {
            index = 1;
            cout << endl;
        }
    }
    cout << endl;
}

void testFoo()
{
    vector<int> arr(1000000);
    iota(arr.begin(), arr.end(), 1);
    random_shuffle(arr.begin(), arr.end());
    
    Foo f1(arr);
    //f1.fooPrint();

    auto t1 = std::chrono::system_clock::now();
    // 将时间点转换为时间戳（以纳秒为单位）
    Foo f2 = f1.sorted();
    
    auto t2 = std::chrono::system_clock::now();
    // 将时间点转换为时间戳（以纳秒为单位）
    auto timestamp = t2 - t1;
    cout << "耗时：" << fixed << setprecision(2) <<
        std::chrono::duration_cast<std::chrono::microseconds>(timestamp).count() << "us" << std::endl;

    auto t3 = std::chrono::system_clock::now();  
    Foo f3 = std::move(f1).sorted();

    auto t4 = std::chrono::system_clock::now();   
    timestamp = t4 - t3;
    cout << "耗时：" << fixed << setprecision(2) << 
        std::chrono::duration_cast<std::chrono::microseconds>(timestamp).count() << "us" << std::endl;

    //f3.fooPrint();
 }
