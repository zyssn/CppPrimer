#pragma once
#include "../11th_associative_container/include.h"



using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double sales_price) : bookno(book), price(sales_price) {}
	string isbn() const { return bookno; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual void debug();
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
	virtual ~Quote() = default;
	virtual double print_total(ostream &os, size_t n);

private:
	string bookno;
protected:
	double price;
};

double print_total(ostream& os, const Quote& item, size_t n);