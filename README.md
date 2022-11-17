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



## 8.2、 文件输入输出



## 8.3、 string流
