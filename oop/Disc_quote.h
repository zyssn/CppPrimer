#pragma once
#include "Quote.h"
class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t n) const override;
	virtual double print_total(ostream& os, size_t n);

private:
	size_t quantity = 0;
	double discount = 0.0;
};

