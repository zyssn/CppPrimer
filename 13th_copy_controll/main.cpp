#include "../11th_associative_container/include.h"
#include "Employee.h"
#include "TreeNode.h"
#include "HasPtr.h"
#include "Message.h"
#include "Folder.h"
#include "Strvec.h"
#include "String.h"
#include "Foo.h"

using namespace std;

class a {
public:
	int size;
	int* data;
	const int x;
public:
	/*a(int size) : size(size) , x(0) {
		data = new int[size];
	}*/
	/*a(const a& A) {
		size = A.size;
		this->data = new int[size];
	}*/

	a(const a& A) = delete;		// 禁用拷贝构造函数
	~a() {
		delete data;
		data = nullptr;
	}
};
int fun(int);

class test {
public:
	test(int* a, string b, float c) : a(a), b(b), c(c) {}
	test(const test& A) : a(A.a), c(A.c) {
		this->b = A.b;
	}

	void set(int* a, string b, float c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	void print() {
		cout << "a = " << *a << ", b is " << b << ", c = " << c << endl;
	}

private:
	int* a;
	string b;
	float c;
};

int main() 
{
//	Employee A("Jack"), B("Bob"), C("Cat"), D("Dog");
//	Employee E(B);
////	a s(2), b = s;		// 出错，对同一块内存执行了两次析构函数,解决措施是自定义拷贝构造函数进行深拷贝
//
//	
//	TreeNode p2(1);
//	TreeNode p3(2);
//	TreeNode p1(3, &p2, &p3);
//	swapLR(p2, p3);
//
//	BinStrTree p();

	//testHasPtr();

	//testMessage();

	//testStrvec();

	testString();

	//testFoo();

	return 0;
}