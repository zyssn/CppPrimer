#include "../11th_associative_container/include.h"
#include "../12th_dynamically_allocate/QueryResult.h"
#include "../12th_dynamically_allocate/TextQuery.h"
#include "Query.h"

using namespace std;

string fileName = "Alice.txt";
void runQuery(ifstream& ifs, Query& q) {
	TextQuery tq(ifs);
	cout << q;//��ӡ������������˲�����
	cout << q.eval(tq);//��ӡ�������������˲�����
}

int main(int argc, char** argv) {
	ifstream ifs(fileName);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	if (ifs)
		runQuery(ifs, q);
	else
		std::cerr << "Cannot open this file!" << fileName;

}
