#pragma once

#include<map>
#include<string>
#include<vector>
#include<stack>
using namespace std;


struct stu {
	string name;
	int id;
	int classes;

	bool operator==(stu& s) {
		return (s.name == name) && (id == s.id) && (classes == s.classes);
	}
	bool operator!=(stu& s) {
		return (s.name != name) || (id != s.id) || (classes != s.classes);;
	}
};

map<stu, stu> parents;
map<stu, int> mapSize;

void init(map<stu, stu>& map1, map<stu, int>& map2, vector<stu> stus) {
	for (auto st : stus) {
		map1[st] = st;
		map2[st] = 1;
	}
}

stu findParent(stu stu1) {
	stack<stu> st;
	while (stu1 != parents[stu1]) {
		st.push(stu1);
		stu1 = parents[stu1];
	}
	stu res = stu1;
	while (!st.empty()) {
		parents[st.top()] = res;
		st.pop();
	}
	return res;
}

void Union(stu stu1, stu stu2) {
	stu father1 = parents[stu1];
	stu father2 = parents[stu2];

	int size1 = mapSize[father1];
	int size2 = mapSize[father2];

	stu &stuBig = size1 >= size2 ? father1 : father2;
	stu &stuSmall = (stuBig == father1) ? father2 : father1;
	parents[father1] = stuBig;
	parents[father2] = stuBig;
	mapSize[stuBig] = size1 + size2;
	mapSize.erase(stuSmall);
}

bool isSameUnion(stu stu1, stu stu2) {
	
	return parents[stu1] == parents[stu2];
}
