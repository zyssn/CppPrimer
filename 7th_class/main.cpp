#include<iostream>
#include "Sales_data.h"
#include "Screen.h"

using namespace std;

//#define SCREENS 1
#define SALES 2

#ifdef SALES
int main() {
	Sales_data data("28319", 2, 3);

	cout << data.ISBN() << endl;
	Sales_data data2(data);

	cout << data2.ISBN() << endl;
	Sales_data data3 = add(data, data2);
	cout << data3.avg_price() << endl;

	return 0;
}

#endif

#ifdef SCREENS
int main() {
	Screen myscreen(1, 5, 'a');
	cout << myscreen.Content() << endl;

	const char ch = myscreen.get(0, 1);

	cout << ch << endl;

	return 0;
}

#endif

    
