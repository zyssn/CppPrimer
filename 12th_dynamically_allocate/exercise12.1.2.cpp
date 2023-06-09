#include "exercise_12.1.2.h"

extern int c = 10;

void printMem(vector<shared_ptr<int>> arr) {
	for_each(arr.begin(), arr.end(), [](shared_ptr<int> p) {
		cout << *p << " ";
	});
	cout << endl;
}

void fun() {
	vector<shared_ptr<int>> arr;
	int a;

	while (cin >> a) {
		//	arr.push_back(shared_ptr<int>(new int(a)));	// 不要混合使用智能指针和动态指针
		arr.push_back(make_shared<int>(a));				// 正确
	}

	printMem(arr);

	//for_each(arr.begin(), arr.end(), [](shared_ptr<int> p) {
	//	delete p;
	//	p = nullptr;
	//});

	shared_ptr<int> p = arr[0];
	arr.~vector();

}

void process(shared_ptr<int> &ptr) {
	cout << ptr.use_count() << endl;
	auto p = ptr.get();
	delete p;
	cout << ptr.use_count() << endl;
	ptr.reset(new int(3));
}

void close() {
	c = 20;
	cout << "c : " << c << endl;
}

void end_connection(int* ptr)
{
	close();
}

