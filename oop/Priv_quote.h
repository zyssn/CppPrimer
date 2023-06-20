#pragma once
#include "Quote.h"
#include "Disc_quote.h"

class Priv_quote : private Quote
{
public:
	Priv_quote(const string& book, double price, bool isq) :
		Quote(book, price), isQuote(isq) {}
	using Quote::isbn;
	using Quote::print_total;

private:
	bool isQuote = false;
};


void test_ptiv_quote();
