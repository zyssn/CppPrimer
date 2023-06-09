#include "Message.h"

Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message::Message(Message&& m): contents(std::move(m.contents))
{
	move_Folders(&m);
}

Message& Message::operator=(Message& msg)
{
	// TODO: 在此处插入 return 语句
	remove_from_Folders();
	contents = msg.contents;
	folders = msg.folders;
	add_to_Folders(msg);
	return *this;
}

Message& Message::operator=(Message&& msg)
{
	if (this != &msg) {
		remove_from_Folders();
		contents = std::move(msg.contents);
		move_Folders(&msg);
	}

	return *this;
}

void Message::swap(Message &m1, Message &m2)
{
	using std::swap;

	for (auto f : m1.folders) {
		f->remMsg(&m1);
	}
	for (auto f : m2.folders) {
		f->remMsg(&m2);
	}
	swap(m1.folders, m2.folders);
	swap(m1.contents, m2.contents);
	for (auto f : m1.folders) {
		f->addMsg(&m1);
	}
	for (auto f : m2.folders) {
		f->addMsg(&m2);
	}
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::addFldr(Folder* f)
{
	folders.insert(f);
}

void Message::rmvFldr(Folder* f)
{
	folders.erase(f);
}

//将本消息发送给m所有文件夹
void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

void Message::remove_from_Folders()
{
	for (auto f : folders) {
		f->remMsg(this);
	}
}

Folder::Folder(const Folder& f) : title(f.title), msgs(f.msgs)
{
	//拷贝构造新的Folder
	//将老Folder消息集里的消息的set都添加上新Folder的指针
	add_to_Message(f);
}
Folder& Folder::operator=(const Folder& f)
{
	//拷贝赋值运算符函数，同时执行拷贝构造函数功能和析构函数功能
	remove_from_Message();
	title = f.title;
	msgs = f.msgs;
	add_to_Message(f);
	return *this;
}

void Folder::printMsg()
{
	cout << "*****************" << endl;
	for (auto m : msgs) {
		cout << m->contents << endl;
	}
	cout << "*****************" << endl;
	cout << endl;
}

void testMessage()
{
	Message m1(string("111")), m2(string("222")), m3(string("333"));
	Message m4(string("444")), m5(string("555")), m6(string("666"));
	Folder f1("f1"), f2("f2"), f3("f3");

	// f1-> 1,3,4,5   f2-> 1,2,3,6  f3-> 2,4,5,6
	m1.save(f1);
	m1.save(f2);
	m2.save(f3);
	m2.save(f2);
	m3.save(f1);
	m3.save(f2);
	m4.save(f1);
	m4.save(f3);
	m5.save(f1);
	m5.save(f3);
	m6.save(f3);
	m6.save(f2);

	f1.printMsg();
	m1 = m2;
	f1.printMsg();

}
