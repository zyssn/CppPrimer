#include<iostream>
#include "Sales_data.h"

using namespace std;

int main() {
	Sales_data data("28319", 2, 3);

	cout << data.ISBN() << endl;
	Sales_data data2(data);

	cout << data2.ISBN() << endl;
	Sales_data data3 = add(data, data2);

	return 0;
}