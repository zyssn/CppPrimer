#include <iostream>
#include "../../CppPrimer/5th_function/print.h"
using namespace std;

//#define INOUT 1
//#define FINOUT 2
#define STRIO 3

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

int main(char* argc, char** argv) {
	fstream fs;
	fs.open("1.jepg", fstream::out | fstream::binary);
	if (fs.is_open())
		cout << "opened!" << ends;
	fs.write("xyz", 3);
	fs.close();

	return 0;
}

#endif // 

#ifdef STRIO
#include <sstream>
#include <string>
#include <fstream>

struct Person {
	string name;
	vector<string> phones;
};

int main(char* argc, char** argv) {
	fstream fs1;
	fs1.open("a.txt", fstream::in);
	vector<Person> ps;
	string str = "";
	//无sstream版
	while (getline(fs1, str)) {
		string name;
		vector<string> personInfo;
		name = str.substr(0, str.find(' '));
		int index = 0;
		str = str.substr(str.find(' ') + 1);
		do {
			
			if ((index = str.find(' ')) != -1)
				personInfo.push_back(str.substr(0, index));
			else {
				personInfo.push_back(str);
				break;
			}
			str = str.substr(str.find(' ') + 1);
		} while (str != "");
		ps.push_back({ name, personInfo });
	}
	//有sstream版
	fstream fs2;
	fs2.open("a.txt", fstream::in);
	while (getline(fs2, str)) {
		vector<string> personInfo;
		string name = "", word = "";
		istringstream is(str);
		is >> name;
		while (is >> word) {
			personInfo.push_back(word);
		}
		ps.push_back({ name, personInfo });
	}

	ostringstream os;
	string s = "asda ";
	os << s << "asdas" << " " << "afas ";
	cout << os.str() << endl;

	return 0;

}

#endif // 
