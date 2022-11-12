#pragma once
#ifndef PRINT_H
#define PRINT_H

#include<iostream>
#include<string>
using namespace std;

// static 变量
void printCnt() {
	static int cnt = 1;
	cout << cnt << endl;
	cnt++;
}

void print(int i) {
	cout << i << endl;
}

void print(int(&arr)[2]) {
	cout << arr[0] << " " << arr[1] << endl;
}

void print(initializer_list<string> lst) {
	for (auto elem : lst) {
		cout << elem << " ";
	}
	cout << endl;
}

void print(initializer_list<int> lst) {

	for (auto i = lst.begin(); i != lst.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

void print() {
	cout << endl;
}

template<typename T, typename... Args>
void print(const T& t, const Args&... args) {
	cout << t << " ";
	print(args...);
}

void print(vector<int> arr, int index) {
	if (index == arr.size()) {
		cout << endl;
		return;
	}

	cout << arr[index] << " ";
	print(arr, index + 1);
}

//const_cast及重载
inline const string& shorterString(const string& s1, const string& s2) {
	return s1.size() > s2.size() ? s2 : s1;
}

string& shorterString(string& s1, string& s2) {
	auto& r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

constexpr string& shorterStr(string& s1, string& s2) {return s1.size() > s2.size() ? s2 : s1;}

#endif // !PRINT_H
