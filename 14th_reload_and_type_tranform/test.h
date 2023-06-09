#pragma once

#include "../11th_associative_container/include.h"

using namespace std;
extern int sz;

class test1
{
public:
	test1(int a, string b, char c) : a(a), b(b), c(c) {}
	int a;
	string b;
	char c;
};

class test2
{
public:
	test2(int a, string b, char c) : a(a), c(c), b(b) {}
	int a;
	string b;
	char c;
};

class test3
{
public:
	test3(int a, string b, char c) : a(a), b(b), c(c) {}
	int a;
	string b;
	char c;
};

test1 &operator+(test1& t1, test2& t2);
test2 &operator+(test2& t2, test3& t3);

template<typename T>
inline void printTest(T t)
{
	cout << t.a << " " << t.b << " " << t.c << endl;
}

template<typename T>
class ifThenElse {
public:
	ifThenElse(bool flag, T _1, T _2) :flag(true), _1(_1), _2(_2) {}
	T operator()() {
		if (flag) return _1;
		return _2;
	}

private:
	bool flag;
	T _1;
	T _2;
};

class printString {
public:
	printString(istream& is = cin, string str = "") : is(is), str(str) {}
	string operator()() {
		string res = "";
		getline(is, res);
		return res;
	}

private:
	istream &is;
	string str;
};

class addVec {
public:
	addVec(istream& is = cin) :is(is) {}
	void operator()() {
		string str = "";
		while (is >> str) {
			vs.push_back(str);
		}
	}
	void print() {
		for (string s : vs) {
			cout << s << " ";
		}
		cout << endl;
	}

private:
	istream &is;
	vector<string> vs;
};

class stringLen {
public:
	bool operator()(const string &s) {
		return s.size() == sz;
	}
};


bool fun_sl(const string& s);


void test();
void testPrintString();
void testaddVec();
void testLambda();

