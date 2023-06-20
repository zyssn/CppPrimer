#include "../11th_associative_container/include.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Priv_quote.h"
#include "proc_quote.h"
#include "Rectangle.h"
#include "ball.h"
#include "Basket.h"

using namespace std;

void test_Quote() {
	Quote item("aaa", 3);
	Bulk_quote bulk("bbb", 4, 20, 0.8);
	Quote* p = &item;
	//Disc_quote disc("ccc", 5, 30, 0.9);		// ������ʹ�ó�����ඨ�����

	// ����Ӧ�ô�Ż����ָ�룬���Ϊ����ָ��
	vector<shared_ptr<Quote>> arr;
	arr.push_back(make_shared<Quote>(std::move(item)));
	arr.push_back(make_shared<Bulk_quote>(bulk));
	arr.push_back(make_shared<Bulk_quote>("ccc", 5, 30, 0.9));

	for (auto p : arr) {
		p->print_total(cout, 5);
	}
}

void testFigure() {
	Rectangle a(50, 100);
	cout << "�ܳ��ǣ�" << a.perimeter() << " ,�����: " << a.area() << endl;
	ball b(50, 50, 100);
	cout << "������ǣ�" << b.perimeter() << " ,�����: " << b.area() << endl;
}

void testBasket() {
	vector<string> isbns{ "aaa", "aaa", "bbb","ccc","ddd","eee","fff","ddd"};
	vector<int> prices{ 5,5,10,15,20,25,30,20 };

	Basket b;
	for (int i = 0; i < isbns.size(); ++i) {
		b.add_item(Quote(isbns[i], prices[i]));
	}

	b.total_receipt(cout);
}

int main() {
	//test_Quote();
	//test_ptiv_quote();
	//testFigure();
	testBasket();

	return 0;
}
