---

---

# CppPrimer

《C++ Primer》学习笔记，使用VS2022编程

# 7、类

## 7.5 构造函数再探

#### <span alt="modern" style="font-size:22px">构造函数</span>

如果有其他构造函数，最好也提供一个<span alt="emp">默认构造函数</span>。

1. <font>默认构造函数</font>

    ```c++
    class test{
      //
      test() = default; 
    };
    ```

    

2. <font style="clolor:yellow">初始化构造函数</font>

    ```c++
    class test{
      //
    	test() = default; 
    	test(int count) : a(count){}
    private:
    	int a;
    };
    ```

    

3. <font>委托构造函数</font>

    ```C++
    //google的c++规范中提到explicit的优点是可以避免不合时宜的类型变换，缺点无。所以google约定所有单参数的构造函数都必须是显式的，只有极少数情况下拷贝构造函数可以不声明称explicit。例如作为其他类的透明包装器的类。 
    class test{
      //
    	test() = default; 
    	test(int ht = 0, int wd = 0, int len = 0, string cont = "") : height(ht), width(wd), length(len), content(cont) {}
        //委托构造函数
        explicit test(string con) : content(con) {}
        
    private:
    	int height;
        int width;
        int length;
        string content;
    };
    
    //调用时应该进行显式类型转换
    int main(){
        test t("5984"); 				//错
        test t(string("5984")); 		
    }
    ```

    

4. <font>转移构造函数</font>

```c++

```

#### <span alt="modern" style="font-size:22px">聚合类</span>：C++中的结构体

当满足以下条件时，称为聚合类：

- 所有成员都是public

- 没有定义任何构造函数

- 没有类内初始值

- 没有基类，也没有virtual函数

    

```C++
class Data(){
public:
	int val;
    string name;
};

//初始化要按照顺序，且列表长度不能超过定义变量的个数
Data data1 = {0, "Jack"};	//正确

```

#### <span alt="modern" style="font-size:22px">静态成员</span>

- 静态成员函数内不能有this指针，也不能由this调用
- 静态成员不与任何对象绑定
- 静态成员使用：：域作用符直接访问
- 静态成员变量可以是不完全类型，可以作为非静态成员函数的默认实参

# 8、IO类

## 8.1、 IO类

| 头文件   | 类型(w表示宽字节)                  |
| -------- | ---------------------------------- |
| iostream | istream, wistream 从流读取数据     |
|          | ostream, wostream 向流写入数据     |
|          | iostream, wiostream 读写流         |
| fstream  | ifstream, wifstream 从文件读取数据 |
|          | ofstream, wofstream 向文件写入数据 |
|          | fstream, wfstream 读写文件         |
| sstream  | istream, wistream 从string读取数据 |
|          | ostream, wostream 向string写入数据 |
|          | iostream, wiostream 读写string     |

​	 2            1           0

<span alt="modern">bad</span><span alt="modern">fail</span><span alt="modern">eof</span>				//寄存器分布

```c++
#include <iostream>
using namespace std;

//使用cin.clear()函数可以操作默认的寄存器
int main() {
	istream &is = cin;
	int a;
	cin >> a;
	auto old_state = cin.rdstate();
	cin.clear(~cin.badbit);
	if (cin.good())
		print("good!");
	if (cin.fail())
		print("fail!");
	print(old_state);
	return 0;
}
```

<font>操作符</font>

- endl:输出缓冲区内容及换行，然后刷新缓冲区
- ends:输出缓冲区及<span alt="emp">空字符</span>，然后刷新缓冲区
- flush:刷新缓冲区，不加任何内容
- unitbuf:任何输入操作都会立刻flush一次缓冲区
- nounibuf:停止unibuf，恢复正常刷新

<span style="color:red">程序崩溃，缓冲区不会被刷新</span>

<font>关联输入和输出流</font>

可以将一个istream关联到另一个ostream上，切换时立即刷新关联的ostream

```c++
cin.tie(&cout);
ostream *old_tie = cin.tie(nullptr);
cin.tie(&cerr);		//切换后cin会刷新cerr而不再是cout
cin.tie(old_tie);
```



## 8.2、 文件输入输出

#include <fstream>

| fstream fstrm           | 创建文件流                    |
| ----------------------- | ----------------------------- |
| fstream fstrm(s)        | 创建文件流，并打开s           |
| fstream fstrm(s,  mode) | 创建文件流，并以mode模式打开s |
| fstrm.open(s)           | 返回void                      |
| fstrm.close()           | 返回void                      |
| fstrm.is_open()         | 返回bool值                    |

<font>mode选取</font>

| in     | 读                       |
| ------ | ------------------------ |
| out    | 写                       |
| app    | 每次都在末尾写           |
| ate    | 打开文件后立即定位到末尾 |
| trunc  | 截断                     |
| binary | 二进制方式               |

## 8.3、string输入输出

#include <sstream>:分为istringstream和ostringstream

使用stringstream可以极大提高处理字符串效率

```c++
/*给定文件内容为：
morgan 2015555151 865542151
drew 251961616
lee 165132464 65326984 654632494 
*///将其读入如下向量中
struct Person {
	string name;
	vector<string> phones;
};
fstream fs1;
fs1.open("a.txt", fstream::in);
vector<Person> ps;
string str = "";
//无sstream版
while (getline(fs1, str)) {
    string name;
    vector<string> personInfo;
    name = str.substr(0, str.find(' '));
    int index = 0;
    str = str.substr(str.find(' ') + 1);
    do {
        if ((index = str.find(' ')) != -1)
            personInfo.push_back(str.substr(0, index));
        else {
            personInfo.push_back(str);
            break;
        }
        str = str.substr(str.find(' ') + 1);
    } while (str != "");
    ps.push_back({ name, personInfo });
}
//有sstream版
fstream fs2;
fs2.open("a.txt", fstream::in);
while (getline(fs2, str)) {
    vector<string> personInfo;
    string name = "", word = "";
    istringstream is(str);
    is >> name;
    while (is >> word) {
        personInfo.push_back(word);
    }
    ps.push_back({ name, personInfo });
}
```

# 9、 顺序容器

## 9.1 顺序容器

### 顺序容器

<font>forward_list</font>、<font>list</font>、<font>vector</font>、<font>deque</font>、<font>string</font>、加一个特殊的 <font style="background-color:green"> array </font>

### 初始化、swap、赋值assign

### 关系运算符

除array外，其他同种泛型的变量可以进行大小比较

## 顺序容器操作

### 添加元素

​	forward_list有自己的insert和emplace函数，不支持push_back和emplace_back函数

​	vector和string不支持push_front和emplace_front函数

| emplace_back()/push_back()   |                      |
| ---------------------------- | -------------------- |
| push_front()/emplace_front() |                      |
| insert(p, t)                 | 在迭代器p之前插入值t |
| insert(p, n, t)              |                      |
| insert(p, il)                | p前插入元素值列表il  |
| emplace(p, args)             |                      |

### 删除元素

​	array不能删除元素

​	forward_list有自己的erase 函数，不支持pop_back函数

​	vector和string不支持pop_front函数

| pop_back()  |                                         |
| ----------- | --------------------------------------- |
| pop_front() |                                         |
| erase(p)    | p---迭代器                              |
| erase(b, e) | 迭代器范围[b, e],返回下一个位置的迭代器 |
| clear()     |                                         |

### forward_list

| lst.before_begin()         | 返回首元素之前的迭代器，不可以解引用                  |
| :------------------------- | ----------------------------------------------------- |
| lst.cbefore_begin()        |                                                       |
| lst.insert_after(p, t)     |                                                       |
| lst.insert_after(p, n, t)  |                                                       |
| lst.insert_after(p, b, e)  | b,e是其他容器的迭代器，将其他容器b-e之间元素插入p位置 |
| lst.insert_after(p, il)    |                                                       |
| lst.emplace_after(p, args) |                                                       |
| lst.erase_after(p)         |                                                       |
| lst.erase_after(b, e)      |                                                       |

### resize

resize不能用于array

| tem.resize(n)    |      |
| ---------------- | ---- |
| tem.resize(n, m) |      |

## 适配器

<font>适配器(adaptor)</font>：是一种通用概念，其接受一种已有的容器类型，使行为看起来像另一种类型，例如栈，底层可以是vector，行为就是栈的行为。

| size_type      | 当前类型最大对象的大小 |
| -------------- | ---------------------- |
| value_type     | 元素类型               |
| container_type | 底层容器类型           |

# 10、泛型

## lambda

格式：<span alt="underline">[函数对象参数](函数参数)修饰符->返回值类型{函数体}</span>

## bind

#include<functional>,占位符需要使用namespace placeholder

## 迭代器

### 五类迭代器

#### 输入迭代器

实例：istream_iterator,只用于顺序访问以及单项扫面算法，如find(), accumulate()

#### 输出迭代器

实例：ostream_iterator，只写而不读元素，只能向输出迭代器输入一次

```cpp
//输入迭代器
istream_iterator<int> int_it(cin);
istream_iterator<int> int_eof;
while (int_it != int_eof) {
    list.push_back(*int_it++);
}
print(list);

//输出迭代器
ostream_iterator<int> out_it(cout, " ");
for (auto l : list) {
    *out_it++ = l;
}
cout << endl;

copy(list.begin(), list.end(), out_it);
cout << endl;

```

#### 前向迭代器

迭代器只能延一个方向移动，可以多次读写同一个元素

#### 双向迭代器

除了支持前向迭代器操作，还支持++和--操作，forward_list上的迭代器全部是前向迭代器。

#### 随机访问迭代器

提供在常量时间内访问序列任意元素的能力，还支持双向迭代器的所有功能。

### 特定容器算法

对于<font>list</font>、<font>forward_list</font>，应该优先使用成员函数版本，而不是通用算法。

```cpp
forward_list<int> ist{ 1,2,3,7,8,9,3,3 };
forward_list<int> ist2{ 4,5,6 };
ist.sort([](int a, int b) {
	return a < b;
});

ist.merge(ist2);
unordered_map<int, int> hash;
for_each(ist.begin(), ist.end(), [&hash](int a) {
	hash[a]++;
});

ist.remove_if([&hash](int a) -> bool{
	hash[a]--;
	return hash[a] != 0;
});
ist.reverse();

auto list_it = ist.begin();
for (; list_it != ist.end(); ) {
	cout << *list_it++ << " ";
}
cout << endl;
```

# 关联容器

## set、map

set--------------------集合，元素有序且不重复

multiset-------------集合，元素有序且不重复

map------------------字典，有序键值对，key不重复

multimap-----------字典，有序键值对，key可重复

------

unordered_set--------------------集合，元素无序且不重复

unordered_multiset-------------集合，元素无序且不重复

unordered_map------------------字典，键值对，key不重复

unordered_multimap-----------字典，键值对，key可重复

### pair

#### 构造函数

pair<T1, T2> p;

pair<T1, T2> p(v1, v2);

pair<T1, T2> p = {v1, v2};

#### 操作

auto p = make_pair(v1, v2)

p.first

p.second

#### 比较

a == b   <=>  (a.first == b.first && a.second == b.second)

a > b     <=>  (a.first > b.first || (a.first == b.first && a.second > b.second))

a != b    <=>  (!(a==b))



## multimap、multiset

### 与set，map区别：

1. 可以有重复的值（或key值）
2. 可以使用find，lower_bound(), upper_bound()、equal_range()函数

```C++

for (auto it_be = res.lower_bound('a');it_be != res.upper_bound('a'); ++it_be) {
    cout << "score = " << it_be->second << endl;
}

for (auto pos = res.equal_range('a'); pos.first != pos.second; ++pos.first) {
	cout << "score = " << pos.first->second << endl;
}

cout << res.count('a') << endl;
auto it = res.find('b');
while (it != res.upper_bound('b')) {
    cout << "score = " << it->second << endl;
    it++;
}
```



# 12、动态内存

## 动态内存与智能指针

### shared_ptr

使用方式同指针，需要指定需要的类型

#### shared_ptr和unique_ptr都支持的操作

| shared_ptr和unique_ptr都支持的操作 |                               |
| ---------------------------------- | ----------------------------- |
| shared_ptr<T> sp                   | 空智能指针                    |
| unique_ptr<T> up                   |                               |
| p                                  |                               |
| *p                                 |                               |
| p->mem                             |                               |
| p.get()                            | 返回p中保存的指针。要小心使用 |
| swap(p,  q)                        | 交换p和q指针                  |
| p.swap(q)                          |                               |

#### shared_ptr独有的操作

| make_shared<T>(args) | 返回一个shared_ptr，指向一个动态分配的类型为T的对象 |
| -------------------- | --------------------------------------------------- |
| shared_ptr<T>p(q)    | p是shared_ptr q的拷贝指针，会增加q的计数器          |
| p = q                | p,q是同种类型，引用导致q计数器减1,p计数器加1        |
| p.unique()           | 返回p.use_count()==1?                               |
| p.use_count()        | 返回与p共享对象的智能指针数量，会影响速度           |

