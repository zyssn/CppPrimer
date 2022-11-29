#include<iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <string>

//#define vec 1
//#define lst 2
//#define flst 3
//#define arr 4
#define str 5

using namespace std;

template<typename T> void print(T t) {
	for (auto a : t) {
		cout << a << " ";
	}
	cout << endl;
}

void print(forward_list<int> flist) {
	auto it = flist.before_begin();
	auto curr = flist.begin();
	while (curr != flist.end()) {
		cout << *curr++ << " ";
	}
	cout << endl;
}

template<typename T> void push(T& t, int i) {
	auto it = t.begin();
	for (int index = 1; index <= i; ++index) {
		it = t.insert(it, index);
	}
}

void push(forward_list<int>& flist, int i) {
	auto it = flist.before_begin();
	flist.insert_after(it, 1);
	auto curr = flist.begin();
	for (int index = 2; index <= i; ++index) {
		flist.insert_after(curr, index);
		curr++;
	}
}

void moveEle(forward_list<int>& flist) {
	auto prev = flist.before_begin();
	auto it = flist.begin();
	while (it != flist.end()) {
		if (*it % 2 == 1)
			it = flist.erase_after(prev);
		else {
			prev = it;
			++it;
		}
	}
}

#ifdef vec
int main() {
	vector<int> res;
	push(res, 8);
	array<int, 30> a({2,5,6,4,2,9,7});
	array<int, 30> b{ 2,4,5,9,8,7 };
	array<int, 30> c;
	auto it = res.begin();
	print(res);
	bool flag = a > b;
	if (flag)
		cout << " > " << endl;
	swap(a, c);
	cout << a[2] << endl;
	return 0;
}

#endif // 


#ifdef flst
#include<forward_list>

int main() {
	forward_list<int> flist;
	vector<int> arr{ 0,1,2,3,4,5 };
	push(flist, 8);
	print(flist);
	moveEle(flist);
	print(flist);
	flist.insert_after(flist.begin(), arr.begin(), arr.end());
	print(flist);
	flist.resize(25, 1);
	print(flist);

	auto it = arr.begin();
	
	arr.assign(25, 0);
	
	arr.push_back(8);
	cout << arr.capacity() << endl;
	
	return 0;
}

#endif // lst

#ifdef str
#include "Date.h"
#include<stack>

int main() {
	string st = "Hello World!";
	const char* cp = "hello world";

	cout << st.compare(0, 0, cp) << endl;

	string s2 = "6.253er5gdf";
	cout << stof(s2) << endl;

	Date date1("1/1/1990");
	date1.print();
	Date date2("Jul 25,2004");
	date2.print();
	Date date3("Dec 8 2600");
	date3.print();
	string s;
	while (getline(cin, s)) {
		Date date(s);
		date.print();
	}

	vector<int>::value_type arr;
	arr = 15;
	stack<int>::value_type a;

	return 0;
}


#endif
