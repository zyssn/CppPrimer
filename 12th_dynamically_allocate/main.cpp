#include"StrBlob.h"
#include "../5th_function/print.h"
#include "exercise_12.1.2.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "unique_ptr.h"
#include "test.h"
#include "exercise_12_2_1.h"
#include "TextQuery.h"

using namespace std;
#define def1 1

class date {
private:
	int year;
	int day;
	int month;

public:
	date(int y, int m, int d) :year(y), month(m), day(d) {}
	date() = default;
	int getYear() { return year; };
};

void runQueries(ifstream& infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word  or Q to quit ! : ";
		string s;
		//输入单词查询 or 输入Q 退出 
		if (cin >> s && (s != "q" && s != "Q")) myprint(cout, tq.query(s)) << endl;
		else break;
	}
}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*shared_ptr<string> p1 = make_shared<string>(10, '9');
	shared_ptr<string> p2 = p1;
	shared_ptr<date> p3 = make_shared<date>(1970, 1, 1);
	auto p4 = make_shared<date>(2022, 12, 10);
	p3 = p4;
	cout << *p1 << endl;
	cout << p3.use_count() << endl;
	if (!p3.unique()) {
		cout << p3->getYear() << endl;
	}*/

	//StrBlob b1;
	//{
	//	initializer_list<string> il = { "a", "an", "the" };
	//	StrBlob b2(il);
	//	b1 = b2;
	//	b2.push_back("about");
	//	cout << b2.front() << endl;
	//	cout << b1.use_count() << endl;
	//	b1.pop_back();
	//	cout << b2.back() << endl;
	//	b2.pop_back();
	//}
	//cout << b1.front() << endl;
	//cout << b1.use_count() << endl;
	//cout << b1.back() << endl;

	//fun();

	int q = 88;
	
	//// 调用删除器处理智能指针
	///*shared_ptr<int> p(&q, end_connection);*/

	//// 也可以使用lambda函数处理
	//shared_ptr<int> p(&q, [](int* t) {
	//	close();		// 模拟释放资源
	//});


	////process(p);
	//cout << "*p = " << *p << endl;

	// 自定义unique_ptr删除器
	//unique_ptr<int, uniqueDeleter> p(&q);
	//cout << *p << endl;

	/*test_12_1_5_2();*/
	//sptrRecursionUse();

	//testStrBlobPtr();

	//exercise_1();
	//exercise_2();

	//shared_ptr<int> sp(new int[10]);

	//for (int i = 0; i < 10; ++i) {
	//	*(sp.get() + i) = i;
	//}
	//int* sq = sp.get();
	//sp.reset();


	//allocator<StrBlob> alloc;
	//auto strP = alloc.allocate(4);
	//auto strQ = strP;
	//alloc.construct(strQ++);
	//alloc.construct(strQ++, initializer_list<string>({ "a", "ab", "abc", "abcd" }));
	//alloc.construct(strQ++, initializer_list<string>({ "A", "AB", "ABC" }));
	//alloc.construct(strQ++, initializer_list<string>({ "X", "XY", "XYZ" }));
	//
	//while (strQ != strP) {
	//	alloc.destroy(--strQ);
	//}
	//alloc.deallocate(strP, 4);

	/*****************************
	* 测试allocator API
	* 文件 ： test.cpp test.h
	******************************/
	//testAllocater();

	/*****************************
	* 测试 TextQuery类功能
	* 功能 ： 1.文件读取后，记住单词出现的每一行
	*		 2.提取每个单词的行号
	*		 3.行号必须升序且无重复
	*		 4.能打印给定行的文本 使用vector<string>
	******************************/
	string fileName = "mountain.txt";
	//ifstream in(fileName);
	//if (in.is_open()) {
	//	runQueries(in);
	//}
	//else cout << " open file error" << endl;

	MyTextQuery mtq(fileName);
	MyTextQuery mtq2(mtq);
	string word;
	cin >> word;
	mtq2.myprint(word);

	return 0;
}

