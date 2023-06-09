#ifndef SALES_DATA_H
#define SALES_DATA_H
#include"../11th_associative_container/include.h"

using namespace std;

class Sales_data {

friend Sales_data add(Sales_data& data1, Sales_data& data2);
friend istream& read(istream& is, Sales_data& trans);
friend ostream& print(ostream& os, const Sales_data&);
friend istream& operator>>(istream& is, Sales_data& sd) {
	is >> sd.isbn >> sd.units_sold >> sd.revenue;
	return is;
}
friend ostream& operator<<(ostream& os, const Sales_data &sd) {
	os << "isbn : " << sd.isbn << ", unit_sold : " << sd.units_sold << " ,avg : " << sd.avg_price();
	return os;
}

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
	inline double avg_price() const;
	~Sales_data();
	
private:
	string isbn;
	unsigned units_sold;
	double revenue;

};


double Sales_data::avg_price() const {
	return units_sold == 0 ? 0 : (double)revenue / units_sold;
}

#endif // !SALES_DATA_H




