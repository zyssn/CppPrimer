#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
#include<stdlib.h>
using namespace std;

class Sales_data {
public:
	Sales_data(string isbn, unsigned unit_sold, double revenue): isbn(isbn), \
		units_sold(unit_sold), revenue(revenue) {}
	string ISBN() { return this->isbn; }
	Sales_data& combine(Sales_data data);
	Sales_data* add(Sales_data data1, Sales_data data2) {
		return new Sales_data(data1.isbn, data1.units_sold, data1.revenue + data2.revenue);
	}
	void read(istream& cin, int trans) {
		
	}
	double avg_price() const;

private:
	string isbn;
	unsigned units_sold;
	double revenue;
};


#endif // !SALES_DATA_H




