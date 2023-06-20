#include "Priv_quote.h"


void test_ptiv_quote() {
	Priv_quote pq("ddd", 40.0, true);

	cout << pq.isbn() << endl;
	pq.print_total(cout, 10);
}
