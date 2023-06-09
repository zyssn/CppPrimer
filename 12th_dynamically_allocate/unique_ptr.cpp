#include "unique_ptr.h"

int d = 10;

void close_unique()
{
	d = 20;
	cout << "d : " << d << endl;
}

void test_12_1_5_2()
{
	typedef unique_ptr<int> intP;

	int x = 1024, * p = &x, * p2 = new int(2048);

	//intP P0(x);
	//intP P1(p);
	intP P2(p2);
	//intP P3(&x);
	intP P4(new int(2048));
	//intP P5(P2.get());
	
}

void end_unique(int* p, void *close) {
	close = close_unique;
}

void sptrRecursionUse() {

	for (int i = 0; i < 5; ++i) {
		shared_ptr<int> p1;
		shared_ptr<int> p2(p1);
		p1 = p2;

		cout << p1.use_count() << endl;
	}
}