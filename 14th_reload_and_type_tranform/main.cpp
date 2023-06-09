#include "test.h"
using namespace std;


int main() {
	test1 t1(1, string("aaa"), 'a');
	test2 t2(2, string("bbb"), 'b');
	test3 t3(3, string("ccc"), 'c');

	printTest<test1>(t1 + t2);
	printTest<test2>(t2 + t3); 
	//test();
	//testPrintString();
	/*testaddVec();*/
	testLambda();

	return 0;
}