#pragma once
#include "../11th_associative_container/include.h"
using namespace std;

class String
{
	friend ostream& operator<<(ostream& os, String s) {
		for (auto p = s.begin(); p != s.end(); ++p) {
			os << *p;
		}
		return os;
	}
	friend istream& operator>>(istream& is, String& s) {
		char ch;
		while (is.get(ch)) {
			if (ch == '\n')
				break;
			s.push_back(ch);
		}
		
		// 输入运算符必须处理输入可能失败的情况，而输出运算符不需要
		if (!is) {
			s = String();
		}

		return is;
	}
public:
	String() :element(nullptr), first_free(nullptr), cap(nullptr) {
		/*this->resize(64, '\0');*/
	}
	String(const string&);
	String(const char* str);
	String(const String&);
	String& operator=(const String&);
	char operator[](size_t n);
	~String();
	void reserve(size_t len);
	void resize(size_t len, char c);
	void push_back(const char&);
	size_t size() const { return first_free - element; }
	size_t capacity() const { return cap - element; }
	char* begin() const { return element; }
	char* end() const { return first_free; }

private:
	static allocator<char> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	pair<char*, char*> alloc_n_copy(const char*, const char*);	//
	void free();							//销毁元素并释放内存
	void reallocate();						//获取更多内存并拷贝内容
	char* element;
	char* first_free;
	char* cap;
};

void testString();
