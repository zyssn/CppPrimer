#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<sstream>
#include "../5th_function/print.h"

using namespace std;


int main() {
	initializer_list<int> ilst{ 1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> vec{ 1,1,2,2,2,3,4,5,6,7 };
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());
	vector<double> v{ 1.26,5.63,5.12,2.3,6.33 };
	cout << accumulate(v.cbegin(), v.cend(), 0.0) << endl;
	if (equal(vec.cbegin(), vec.cend(), ilst.begin())) {
		cout << "equal" << endl;
	}
	else cout << "unequal" << endl;
	
	string str;
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

	return 0;
}