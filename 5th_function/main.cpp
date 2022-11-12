#include<iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include "print.h"
#include "functionPointer.h"

using namespace std;

//constexpr常用于常量表达式的函数，且返回只能是return语句
constexpr double pi() { return 3.14; }
constexpr bool isPrime(int num) { return num % 2 == 0; }

// 函数指针 （括号必不可少）
int (*pf)(int a, int b);
int add2(int a, int b) { return a + b; }
int minus2(int a, int b) { return a - b; }
int multi2(int a, int b) { return a * b; }
int div2(int a, int b) { assert(b); return a / b; }

void test1(int a, int b) {
	vector<decltype(pf)> vec;

	vec.push_back(*add2);
	vec.push_back(*minus2);
	vec.push_back(*multi2);
	vec.push_back(div2);

	string arr[] = { "a + b =", "a - b =", "a * b =", "a / b =" };

	for (int i = 0; i < vec.size(); ++i) {
		print(arr[i], vec[i](a, b));
	}

}


int main() {
	/*for (int i = 1; i < 10; ++i) {
		printCnt();
	}*/

	int a = 2;
	int b[2] = { 2, 3 };
	vector<int> arr{ 1, 5, 9, 7, 5, 3 };

	print(a);
	print(b);
	print({ "jsdi", "fhsod", "sda" });
	print({ 5, 6, 7, 8, 9 });
	print( 5, 6.5, "sadsd", 'c');
	print(arr, 0);

	//内联函数以及constexpr使用
	time_t t1 = time(NULL);
	string s1 = "ads";
	string s2 = "sad";
	cout << shorterString(s1, s2) << endl;

	time_t t2 = time(NULL);
	cout << (t2 - t1) * 1000 << "ms" << endl;

	print(pi());
	print(isPrime(2021));


	print(shorterStr(s1, s2));
	
	//assert使用
	//assert(0);

	pf = &maxNum;
	print(pf(5, 4));
	pf = &minNum;
	print(pf(5, 4));

	bool (*pf2)(int, int) = equalNum;
	if (pf2(4, 4))
		print("equal number!");
	else
		print("Not equal number!");

	//使用auto或decltype简化声明
	decltype(maxNum) *pf3;
	auto pf4 = minNum;
	pf3 = minNum;
	print(pf3(4, 7));
	print(pf4(4, 7));
	using pf5 = int(*)(int, int);
	pf5 pf6 = maxNum;
	print(pf6(4, 8));

	cout << "*************************" << endl;
	cout << "the number of cin is " << a << " & " << b[1] << endl;
	test1(a, b[1]);

	return 0;
}
