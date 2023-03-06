#include "StrBlob.h"


void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob!");
	return data->pop_back();
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob!");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob!");
	return data->back();
}

size_t StrBlob::use_count()
{

	return data.use_count();
}


void StrBlob::check(size_type i, const string& msg) const{
	if (i >= data->size())
		throw out_of_range(msg);
}

