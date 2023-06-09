#include "HasPtr.h"


void HasPtr::swap(string* l, string* r) {
	string* tmp = l;
	l = r;
	r = l;
}

HasPtr& HasPtr::operator=(HasPtr hp) {
	using std::swap;
	swap(*this, hp);
	return *this;
}

bool HasPtr::operator<(const HasPtr& hp) const
{
	return *this->ps < *hp.ps;
}

void swap(HasPtr& l, HasPtr& r)
{
	using std::swap;
	cout << "swap string : " << endl << *l.ps << endl << *r.ps << endl;
	swap(l.ps, r.ps);
	swap(l.i, r.i);
}

void printVhp(vector<HasPtr> vph)
{
	for (auto ph : vph) {
		cout << ph.getps() << " ";
	}
	cout << endl;
}

void testHasPtr()
{
	HasPtr p1("hello"), p2("hallo"), p3("ahksj"), p4("soafj");
	HasPtr p5("asfka"), p6("trbdd"), p7("bdssad"), p8("ewrefas");
	vector<HasPtr> vhp{p1, p2, p3, p4, p5, p6, p7, p8};
	sort(vhp.begin(), vhp.end());
	printVhp(vhp);

	return;
}
