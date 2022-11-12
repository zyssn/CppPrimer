#include "Sales_data.h"
#include <cassert>

Sales_data &Sales_data::combine(Sales_data &data) {
	this->revenue += data.revenue;
	this->units_sold += data.units_sold;
	return *this;
}

Sales_data::Sales_data(string isbn) {
	this->isbn = isbn;
	this->units_sold = 0;
	this->revenue = 0.0;
}
Sales_data::Sales_data(Sales_data const &data) {
	this->isbn = data.isbn;
	this->units_sold = data.units_sold;
	this->revenue = data.revenue;
}

Sales_data::Sales_data(Sales_data* data)
{
	this->isbn = data->isbn;
	this->units_sold = data->units_sold;
	this->revenue = data->revenue;
}

Sales_data::~Sales_data(){
}

Sales_data add(Sales_data &data1, Sales_data &data2) {
	Sales_data sum = data1;
	sum.combine(data2);

	return sum;
}

istream& read(istream& is, Sales_data &data) {
	return is;
}

ostream& print(ostream& os, const Sales_data&)
{
	return os;
}
