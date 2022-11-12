#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

namespace use_string
{
	//init
	string s1;			//默认构造函数，值为空
	string s2(s1);		//拷贝构造函数
	string s3 = s1;		//拷贝构造函数，重载了等号
	string s4("nlp");	//赋值构造函数
	string s5 = "nlp";	//同上，重载等号
	string s6(5, 'c');	//赋值构造函数

	//operation
}


int main()
{
	/*vector<string> arr;
	string s;

	while (cin >> s)
	{
		arr.push_back(s);
	}
	cout << endl;


	decltype(arr)::const_iterator it = arr.begin();
	for (; it < arr.end(); it+=5) 
	{
		cout << *it << " ";
	}
	cout << endl;

	ptrdiff_t diff = arr.end() - arr.begin();
	cout << diff << endl;


	
	for (decltype(arr.size()) i = 0; i < arr.size(); ++i) {
		cout << arr[i]
			 << " ";
	}
	cout << endl;*/

	char* st = new char[10];
	memset((char*)st, 'a', 10);
	cin.getline(st, 10);

	for (int i = 0; i < 10; ++i) {
		cout << st[i];
	}

	int arr[4][4][4] = {{{0}, {1}, {2}}, {{3},{4},{5}}, {{7},{8},{9}}};
	int ia[3][4] = {{0}, {4}, {8}};
	ia[2][3] = arr[0][0][0];
	int (&row)[4][4] = arr[1];

	for (int i = 0; i < 4; ++i) {
		cout << row[i][0] << endl;
	}


	return 0;
}