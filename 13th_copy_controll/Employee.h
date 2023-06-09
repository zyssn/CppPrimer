#pragma once
#include "../11th_associative_container/include.h"
using namespace std;

class Employee
{
public:
	static int pubid;
	Employee(string name) : name(name) {
		this->id = pubid++;
	}
	Employee(const Employee& Emp) {
		this->name = Emp.name;
		this->id = Emp.pubid++;
	}
	

private:
	
	string name;
	int id;
	static int initPubId() {
		return 10000;
	}
};


