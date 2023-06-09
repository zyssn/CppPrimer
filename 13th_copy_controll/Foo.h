#pragma once
#include "../11th_associative_container/include.h"
using namespace std;

class Foo
{
public:
	Foo(vector<int> dt) : data(dt) {}
	//Foo(Foo&& dt) : data(dt.data) {
	//	dt.data.erase(dt.data.begin(), dt.data.end());
	//}
	Foo sorted()&&;
	Foo sorted() const&;
	void fooPrint();

private:
	vector<int> data;
};

void testFoo();