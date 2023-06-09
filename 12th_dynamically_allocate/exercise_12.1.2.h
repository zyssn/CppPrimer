#pragma once

#include "../11th_associative_container/include.h"
using namespace std;
extern int c;
void fun();
void printMem(vector<int*> arr);
void process(shared_ptr<int> &ptr);

void close();

void end_connection(int* ptr);