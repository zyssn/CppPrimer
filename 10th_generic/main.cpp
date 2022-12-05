#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
#include<sstream>
#include<unordered_map>

#include "../5th_function/print.h"

using namespace std;
//#define lam
#define iter

#ifdef lam


string substring(string str, string::size_type pos1, string::size_type pos2) {
	return str.substr(pos1, pos2);
}

int main() {
	initializer_list<int> ilst{ 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> vec{ 1,1,2,2,2,3,4 };
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());
	vector<double> v{ 1.26,5.63,5.12,2.3,6.33 };
	cout << accumulate(v.cbegin(), v.cend(), 0.0) << endl;
	if (equal(vec.cbegin(), vec.cend(), ilst.begin())) {
		cout << "equal" << endl;
	}
	else cout << "unequal" << endl;

	/*string str;
	vector<string> info;
	while (getline(cin, str)) {
		istringstream is(str);
		string name = "";
		while (is >> name) {
			info.push_back(name);
		}
	}
	print(info);
	sort(info.begin(), info.end());
	print(info);

	int sz = 4;
	auto wc = find_if(info.begin(), info.end(), [sz](const string& a) {
		return a.size() >= sz;
		});

	for_each(wc, info.end(), [](const string& s) {cout << s << " "; });*/
	cout << endl;

	vector<int> sumVec;
	int ss = 0;
	for_each(vec.begin(), vec.end(), [&sumVec, ss](int& a) mutable {
		sumVec.push_back(a + ss);
		ss += a;
		});

	print(sumVec);
	int count = 10;
	auto is_zero = [&count]() -> bool {
		count--;
		return count == 0; 
	};
	while (count > 0) {
		if (!is_zero()) {
			cout << "count = " << count << " : count != 0!" << endl;
		}
		else
			cout << "count = 0!" << endl;
	}

	auto sub_string_0 = bind(substring, placeholders::_1, 0, placeholders::_2);
	string test = "china";
	cout << sub_string_0(test, 3) << endl;


	return 0;
}

#endif // lam


#ifdef iter
#include<deque>
#include <forward_list>
vector<int> test2(vector<int> &vec) {
	vector<int> list;
	::sort(vec.begin(), vec.end());
	unique_copy(vec.begin(), vec.end(), list.begin());
	return list;
}


int main() {
	vector<int> vec = { 1,2,1,2,3,3,4,5,6,7,9,8,5,8,9 };
	auto it = inserter(vec, vec.begin());
	
	*++it = 10;
	print(vec);

	vector<int> list;
	//sort(vec.begin(), vec.end());
	//unique_copy(vec.begin(), vec.end(), back_inserter(list));
	//print(list);

	//istream_iterator<int> int_it(cin);
	//istream_iterator<int> int_eof;
	//while (int_it != int_eof) {
	//	list.push_back(*int_it++);
	//}
	//print(list);
	//ostream_iterator<int> out_it(cout, " ");
	//for (auto l : list) {
	//	*out_it++ = l;
	//}
	//cout << endl;

	//copy(list.begin(), list.end(), out_it);
	////cout << endl;
	//vector<int> dest;
	//reverse_copy(list.begin(), list.end(), dest.begin());
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
	ist.remove_if([&hash](int a)->bool{
		hash[a]--;
		return hash[a] != 0;
		});
	ist.reverse();
	auto list_it = ist.begin();
	for (; list_it != ist.end(); ) {
		cout << *list_it++ << " ";
	}
	cout << endl;
	//print(dest);

	return 0;
}

#endif // DEBUG
