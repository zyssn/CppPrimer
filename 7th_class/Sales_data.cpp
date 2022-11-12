#include "Sales_data.h"
#include <cassert>

Sales_data& Sales_data::combine(Sales_data data) {
	this->revenue += data.revenue;
	this->units_sold += data.units_sold;
	return *this;
}

double Sales_data::avg_price() const {
	assert(units_sold);
	return revenue / units_sold;
}
