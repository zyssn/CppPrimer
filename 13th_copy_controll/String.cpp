#include "String.h"

allocator<char> String::alloc;

String::String(const string& s)
{
	cout << "copy construct string function!" << endl;
	auto data = alloc_n_copy(&s.front(), &s.back()+1);
	element = data.first;
	cap = first_free = data.second;
}

String::String(const String& s)
{
	cout << "copy construct String function!" << endl;
	auto data = alloc_n_copy(s.begin(), s.end());
	element = data.first;
	cap = first_free = data.second;
}

String::String(const char* str)
{
	//确定数组大小
	auto newCapacity = strlen(str);
	//创建内存
	auto newData = alloc.allocate(newCapacity);
	element = newData;
	//复制元素
	auto p = uninitialized_copy(str, str + newCapacity, newData);
	//更新指针
	first_free = p;
	cap = element + newCapacity;
}

String& String::operator=(const String& s)
{
	cout << "copy assign operator!" << endl;
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	element = data.first;
	cap = first_free = data.second;

	return *this;
}

char String::operator[](size_t n)
{
	if (n >= size()) {
		throw("out od range!");
	}

	return *(element + n);
}

String::~String()
{
	free();
}

void String::reserve(size_t len)
{
	if (len <= size()) return;
	size_t tmp = min(len, capacity()) - size();
	while (tmp) {
		push_back('\0');
		tmp--;
	}
}

void String::resize(size_t len, char c)
{
	if (len > capacity()) {
		free();         //释放原内存
		auto newdata = alloc.allocate(len);
		element = first_free = newdata;

		while (len--) {
			alloc.construct(first_free++, c);
		}

		cap = first_free;
		return;
	}

	auto p = element;
	size_t n = len;
	while (n) {
		alloc.construct(p++, c);
		n--;
	}
	if (len <= size()) {
		while (first_free != p) {
			alloc.destroy(--first_free);
		}
	}
}

void String::push_back(const char& c)
{
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}

void String::free()
{
	if (element) {
		for (auto p = first_free; p != element;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(element, cap - element);
	}
}

void String::reallocate()
{
	cout << "reallocating..." << endl;
	size_t newcapacity = size() ? 2 * size() : 64;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = element;

	while (elem != first_free) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();         //释放原内存
	element = newdata;
	first_free = dest;
	cap = element + newcapacity;
}

void testString()
{
	string str = "Hello world!";

	String s("abc");
	vector<string> arr = { "hello", "world!", "Mr. ", "Mary", "thank", "you" };
	vector<String> res;
	for (auto con : arr) {
		res.push_back(con);
	}

	String news;
	cin >> news;
	cout << news << endl;
	cout << news[2] << endl;

	return;
}
