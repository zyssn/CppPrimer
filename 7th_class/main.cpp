#include<iostream>
#include "Sales_data.h"
//#include "Screen.h"
#include "../5th_function/print.h"
//#include "task.h"
//#include "Window_mgr.h"

using namespace std;

#define SCREENS 1
//#define SALES 2
//#define TASK 3


#ifdef SALES
int main() {
	Sales_data data("28319", 2, 3);

	cout << data.ISBN() << endl;
	Sales_data data2(data);

	cout << data2.ISBN() << endl;
	Sales_data data3 = add(data, data2);
	cout << data3.avg_price() << endl;

	return 0;
}

#endif

#ifdef SCREENS
#include "Constructor.h"

int main() {
	//Screen myscreen(4, 5, 'a');
	//cout << myscreen.Content() << endl;

	//cout << myscreen.Content() << endl;
	//print(myscreen.bigCur());
	//print(myscreen.midCur());
	//print(myscreen.smallCur());

	int a = 3, b = 4;
	//Constructor c();	//错、无法调用常量、引用值、类变量
	Constructor c2(a);
	Constructor c1(b);
	// c.print_j()		//错
	c2.print_j();

	cout << "begin:-----------------------------------------" << endl;
	c1.print_t();
	c2.print_t();
	c2.add_t();
	cout << "changed:-----------------------------------------" << endl;
	c2.print_t();
	c1.print_t();

	return 0;
}

#endif

#ifdef TASK

int main() {
	X x;
	cout << sizeof(x) << endl;

	return 0;
}

#endif // TASK


    
