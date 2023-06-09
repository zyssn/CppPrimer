#include "exercise_12_2_1.h"
#include "../11th_associative_container/include.h"

using namespace std;

void exercise_1() {
	const char word1[] = "Hello ";
	const char word2[] = "World!";

	int n = strlen(word1) + strlen(word2) + 1;
	unique_ptr<char[]> p(new char[n]);

	int i = 0;
	for (i = 0; i < strlen(word1); ++i) {
		p[i] = word1[i];
	}
	for (; i < n - 1; ++i) {
		p[i] = word2[i- strlen(word1)];
	}
	p[i] = '\0';

	cout << p << endl;

	p.release();
}

void exercise_2() {
	string word1 = "Hello ";
	string word2 = "World!";

	int n = word1.size() + word2.size() + 1;
	unique_ptr<char[]> p(new char[n]);

	int i = 0;
	for (i = 0; i < word1.size(); ++i) {
		p[i] = word1[i];
	}
	for (; i < n - 1; ++i) {
		p[i] = word2[i - word1.size()];
	}
	p[i] = '\0';

	cout << p << endl;

	p.release();
}
