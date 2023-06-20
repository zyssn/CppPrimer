#include "../11th_associative_container/include.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"
#include "Query.h"

using namespace std;

string fileName = "Alice.txt";
void runQuery(ifstream& ifs, Query& q) {
	TextQuery tq(ifs);
	cout << q;//打印处理对象，重载了操作符
	cout << q.eval(tq);//打印处理结果，重载了操作符
}

int main(int argc, char** argv) {
	ifstream ifs(fileName);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	if (ifs)
		runQuery(ifs, q);
	else
		std::cerr << "Cannot open this file!" << fileName;

}
