#include"mergeSort.h"
#include"Trie.h"
#include"unionSet.h"
#include<set>

using namespace std;

#define MERGE 0
#define TRIE 0
#define UNION 1

template<typename T>
void print(vector<T> arrs) {
	for (auto arr : arrs) {
		cout << arr << " ";
	}
	cout << endl;
}

#ifndef MERGE

int main() {
	vector<int> arr = {1,4,6,9,2,7,8,1,0,23,6,5};
	mergeSort(arr);
	print(arr);
	return 0;
}

#endif // !MERGE

#ifndef TRIE

int main() {
	Trie* root = new Trie();
	vector<string> words{ "abc", "abcd", "ghf", "abcfe","abghf" };
	vector<string> tests{ "abc", "abghf", "aghf", "ghe","ghfe" };

	for (auto word : words) {
		root->insert(word);
	}
	for (auto test : tests) {
		if (root->search(test)) {
			cout << test << " : " << "finded!!!" << endl;
		}
		else {
			cout << test << " : " << "unfinded!!!" << endl;
		}
	}

	return 0;
}

#endif // !TRIE

#ifdef UNION

int main() {
	vector<stu> stus{ {"Wang", 23, 1}, {"Zhang", 42, 1}, {"Sun", 42, 0}};
	init(parents, mapSize, stus);
	set<int> st;
	st.find

	return 0;
}


#endif // 
