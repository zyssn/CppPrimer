#include "Quote.h"

void Quote::debug()
{
	cout << "Quote.debug() : " << endl;
	cout << "\tbookno : " << bookno << endl;
	cout << "\tprice : " << price << endl;
}

double Quote::print_total(ostream& os, size_t n)
{
	double res = 0.0;
	res = net_price(n);
	os << "Quote total : " << endl;
	os << "ISBN: " << isbn() << " # ,sold: " << n << " ,total due: " << res << endl;
	return res;
}

double print_total(ostream& os, const Quote& item, size_t n)
{
	double res = 0.0;
	res = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # ,sold: " << n << " ,total due: " << res << endl;
	return res;
}
