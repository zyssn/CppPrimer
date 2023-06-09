#pragma once
#ifndef PRINT_H
#define PRINT_H

#include<iostream>
#include<string>
#include <vector>
#include<deque>
#include<unordered_map>
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

template<typename T>
void print(vector<T> arrs) {
	for (auto arr : arrs) {
		cout << arr << " ";
	}
	cout << endl;
}

template<typename T1, typename T2>
void print(unordered_multimap<T1, T2> arrs) {
	for (auto arr : arrs) {
		cout << "key : " << arr.first << ", value : " << arr.second << endl;
	}
	cout << endl;
}

template<typename T1, typename T2>
void print(vector<pair<T1, T2>> arrs) {
	for (auto arr : arrs) {
		cout << "key : " << arr.first << ", value : " << arr.second << endl;
	}
	cout << endl;
}

template<typename T1, typename T2>
void print(pair<T1, T2> arrs) {
	for (auto arr : arrs) {
		cout << "key : " << arr.first << ", value : " << arr.second << endl;
	}
}

template<typename T, typename... Args>
void print(T& t, Args&... args) {
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
