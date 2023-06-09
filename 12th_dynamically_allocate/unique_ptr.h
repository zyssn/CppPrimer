#pragma once

#include "../11th_associative_container/include.h"
using namespace std;
extern int d;

void close_unique();

struct uniqueDeleter {
	void operator()(int* p) const {
		close_unique();
	}
};

void test_12_1_5_2();

void sptrRecursionUse();

