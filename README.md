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

