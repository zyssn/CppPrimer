#include"StrBlob.h"
#include "../5th_function/print.h"

using namespace std;
#define def1 1

//class date {
//private:
//	int year;
//	int day;
//	int month;
//
//public:
//	date(int y, int m, int d) :year(y), month(m), day(d) {}
//	date() = default;
//	int getYear() { return year; };
//};


int main() {
	/*shared_ptr<string> p1 = make_shared<string>(10, '9');
	shared_ptr<string> p2 = p1;
	shared_ptr<date> p3 = make_shared<date>(1970, 1, 1);
	auto p4 = make_shared<date>(2022, 12, 10);
	p3 = p4;
	cout << *p1 << endl;
	cout << p3.use_count() << endl;
	if (p3.unique()) {
		cout << p3->getYear() << endl;
	}*/

	StrBlob b1;
	{
		StrBlob b2 = { "a", "an", "the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.front() << endl;
		cout << b1.use_count() << endl;
	}
	cout << b1.front() << endl;
	cout << b1.use_count() << endl;


	return 0;
}

