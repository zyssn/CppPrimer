#include "Date.h"

vector<string> split(string st, char c) {
	vector<string> res;
	int index = 0;
	string tmp = "";
	for (int i = 0; i < st.size(); ++i) {
		if (st[i] == c) {
			tmp = st.substr(index, i);
			res.push_back(tmp);
			index = i + 1;
		}

	}
	if (index != st.size() && st.substr(index).size() != 0) {
		res.push_back(st.substr(index));
	}
	return res;
}

// 要求适配三种不同字符串输入： Jan 1，1990、1/1/1990，Jan 1 1990
Date::Date(string date) {
	array<string, 12> Month{
		"Jan", "Fib", "Mat", "Apr", "May","Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	unordered_map<string, int> hash;
	for (int i = 0; i < 12; ++i) {
		hash[Month[i]] = i+1;
	}
	vector<string> tmp = split(date, ' ');
	switch (tmp.size())
	{
	case 1:
		tmp = split(date, '/');
		if (tmp.size() == 3) {
			this->day = static_cast<unsigned>(stoi(tmp[0]));
			this->month = static_cast<unsigned>(stoi(tmp[1]));
			this->year = static_cast<unsigned>(stoi(tmp[2]));
		}
		else cout << "print not same as 1/1/1990" << endl;
		break;
	case 2:
		this->month = static_cast<unsigned>(hash[tmp[0]]);
		tmp = split(tmp[1], ',');
		if (tmp.size() == 2 && this->month != 0) {
			this->day = static_cast<unsigned>(stoi(tmp[0]));
			this->year = static_cast<unsigned>(stoi(tmp[1]));
		}
		else cout << "print not same as \'Jan 1，1990\'" << endl;
		break;

	case 3:
		this->month = static_cast<unsigned>(hash[tmp[0]]);
		this->day = static_cast<unsigned>(stoi(tmp[1]));
		this->year = static_cast<unsigned>(stoi(tmp[2]));
		if (this - day == 0 || this->month == 0)
			cout << "cin day or month error" << endl;
		break;
	default:
		cout << "print error!" << endl;
		break;
	}
}