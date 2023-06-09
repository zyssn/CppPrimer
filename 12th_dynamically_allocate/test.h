#pragma once
#include "../11th_associative_container/include.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"

using namespace std;

class MyTextQuery
{
public:
	using line_no = vector<string>::size_type;
	MyTextQuery(string path);
	void myprint(string word);

private:
	map<string, vector<int>> mp;
	string path;
	vector<string> content_in_a_line;

};

void testStrBlobPtr();
void testAllocater();


