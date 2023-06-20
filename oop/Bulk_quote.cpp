#include "Bulk_quote.h"

double Bulk_quote::net_price(size_t n) const
{
	double res = 0;
	if (n < min_qty) {
		res = price * n;
	}
	else {
		res = price * n * discount;
	}

	return res;
}

void Bulk_quote::debug()
{
	cout << "Bulk_quote.debug() : " << endl;
	this->Quote::debug();
	cout << "\tmin_qty : " << min_qty << endl;
	cout << "\tdiscount : " << discount << endl;
}

double Bulk_quote::print_total(ostream& os, size_t n)
{
	double res = net_price(n);
	os << "Bulk_quote total : " << endl;
	os << "ISBN: " << isbn() << " # ,sold: " << n << fixed << setprecision(2) << " ,total due: " << res << endl;
	return res;
}
