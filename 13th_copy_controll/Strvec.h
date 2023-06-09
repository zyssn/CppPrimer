#pragma once
#include "../11th_associative_container/include.h"

using namespace std;

class Strvec
{
public:
	Strvec() :element(nullptr), first_free(nullptr), cap(nullptr) {}
	Strvec(const Strvec&);
	Strvec& operator=(const Strvec&);
	Strvec(Strvec &&s) noexcept;					// �ƶ����캯��
	Strvec& operator=(Strvec&&) noexcept;		// �ƶ���������
	~Strvec();
	void reserve(size_t len);
	void resize(size_t len, string str);
	void push_back(const string&);
	size_t size() const { return first_free - element; }
	size_t capacity() const { return cap - element; }
	string* begin() const { return element; }
	string* end() const { return first_free; }

private:
	static allocator<string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	pair<string*, string*> alloc_n_copy(const string*, const string*);	//
	void free();							//����Ԫ�ز��ͷ��ڴ�
	void reallocate();						//��ȡ�����ڴ沢��������
	string* element;
	string* first_free;
	string* cap;
};


void testStrvec();
void foo(int& x);
void test();
