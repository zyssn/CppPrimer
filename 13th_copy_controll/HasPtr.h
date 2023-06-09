#pragma once
#include "../11th_associative_container/include.h"
using namespace std;

class HasPtr
{
public:
	friend void swap(HasPtr& l, HasPtr& r);
	HasPtr(const string& s) : ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr& hp) : i(hp.i), use(hp.use), ps(hp.ps) {
		++* use;
	}
	string getps() {
		return *this->ps;
	}
	void swap(string* l, string* r);
	HasPtr& operator=(HasPtr hp);
	bool operator<(const HasPtr &hp) const;

private:
	string* ps;
	int i;
	size_t* use;
};

void printVhp(vector<HasPtr> vph);
void testHasPtr();

