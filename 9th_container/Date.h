#pragma once
#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<unordered_map>

using namespace std;

class Date {
private:
	unsigned year = 1970;
	unsigned month = 1;
	unsigned day = 1;

public:
	Date() = default;
	Date(string date);
	void print() {
		cout << year << "-" << month << "-" << day << endl;
	}
};

