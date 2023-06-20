#include "Disc_quote.h"

double Disc_quote::print_total(ostream& os, size_t n)
{
	double res = 0.0;
	res = net_price(n);
	os << "Disc_quote total : " << endl;
	os << "ISBN: " << isbn() << " # ,sold: " << n << " ,total due: " << res << endl;
	return res;
}
