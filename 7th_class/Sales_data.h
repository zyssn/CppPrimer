#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
#include<stdlib.h>
using namespace std;

class Sales_data {

friend Sales_data add(Sales_data& data1, Sales_data& data2);
friend istream& read(istream& is, Sales_data& trans);
friend ostream& print(ostream& os, const Sales_data&);

public:
	Sales_data() = default;
	Sales_data(string isbn, unsigned unit_sold, double revenue): isbn(isbn), \
		units_sold(unit_sold), revenue(revenue * unit_sold) {}
	Sales_data(string isbn);
	Sales_data(const Sales_data &data);
	Sales_data(Sales_data* data);
	//Sales_data(istream& is) { read(is, *this); }
	string ISBN() { return this->isbn; }
	Sales_data &combine(Sales_data &data);

	~Sales_data();
	
private:
	string isbn;
	double avg_price() const;
	unsigned units_sold;
	double revenue;

};


#endif // !SALES_DATA_H




