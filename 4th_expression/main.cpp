#include <iostream>
#include <stdexcept>

using namespace std;

class mytime
{
public:
	int hour;
	int minu;
	int sec;

	mytime(int hour, int minu, int sec) : hour(hour), minu(minu), sec(sec) {}

};


bool is_equal_time(mytime a, mytime b)
{
	if (a.hour == b.hour && a.minu == b.minu && a.sec == b.sec) {
		throw logic_error("time is equal");
		return true;
	}
	else {
		throw runtime_error("time isn't equal!");
		return false;
	}
}

int divd(int a, int b) {
	if (b == 0) {
		throw exception("Integer division by zero。");
	}
	return a / b;
}

int main()
{
	//1.左值与右值的decltype使用
	
	//mytime a(11, 12, 13);
	//mytime b(11, 12, 14);
	//mytime c(11, 12, 13);

	//try {
	//	is_equal_time(a, b);
	//	
	//} catch (runtime_error e) {
	//	cout << e.what() << endl;
	//	
	//	try {
	//		is_equal_time(a, c);
	//	}
	//	catch (logic_error ee) {
	//		cout << ee.what() << endl;
	//	}
	//}
	
	//example: input two int number, output first / second
	
	int a, b;
	while (cin >> a >> b) {
		try {
			int c = divd(a, b);
			cout << "the result number is: " << c << " !" << endl;
			break;
		}
		catch (exception e) {
			cout << e.what() << "\nTry again? Enter y" << endl;
			char c;
			cin >> c;
			if (c != 'y')
				break;
		}
	}

	return 0;
}