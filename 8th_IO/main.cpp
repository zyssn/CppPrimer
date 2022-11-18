#include <iostream>
#include "../../CppPrimer/5th_function/print.h"
using namespace std;

//#define INOUT 1
#define FINOUT 2

#ifdef INOUT

int main() {
	istream &is = cin;
	int a = 8;
	//while(cin >> a);
	auto old_state = cin.rdstate();
	cin.clear(~cin.goodbit & cin.badbit & cin.failbit);
	//if (cin.good())
	//	print("good!");
	//if (cin.fail())
	//	print("fail!");
	//print(old_state);
	cin.tie(&cout);
	ostream* old_tie = cin.tie(nullptr);
	cin.tie(&cerr);		//切换后cin会刷新cerr而不再是cout
	
	cerr << "sdasdf";
	cin >> a;
	cout << "Asda" << "as";
	cin.tie(old_tie);

	return 0;
}

#endif // 

#ifdef FINOUT
#include <fstream>
#include"../../CppPrimer/.vs/CppPrimer/"
int main() {
	fstream fs;
	fs.open("../a.txt", 'rw+');
	if (fs.is_open())
		cout << "opened!" << ends;
	fs.write("xyz", 3);
	fs.close();

	return 0;
}

#endif // 

