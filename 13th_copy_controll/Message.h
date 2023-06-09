#pragma once
#include "../11th_associative_container/include.h"

using namespace std;

class folder;
class Message
{
public:
	friend class Folder;
	// 三/五原则
	explicit Message(const string& str = "") : contents(str) {}
	Message(const Message& m);
	Message(Message&& m);
	Message& operator=(Message& msg);
	Message& operator=(Message&& msg);

	void swap(Message &m1, Message &m2);
	void move_Folders(Message* m);

	void save(Folder& f);
	void remove(Folder& f);
	void addFldr(Folder* f);
	void rmvFldr(Folder* f);
	~Message();

private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder
{
public:
	friend class Message;
	explicit Folder(const string& str = "") : title(str) {}
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	void printMsg();
	void remMsg(Message* m) { msgs.erase(m); }
	void addMsg(Message* m) { msgs.insert(m); }
	~Folder() { remove_from_Message(); }
private:
	string title;
	set<Message*> msgs;
	void add_to_Message(const Folder& f)
	{
		for (auto m : f.msgs)
			m->addFldr(this);
	}

	void remove_from_Message()
	{
		for (auto m : msgs)
			m->rmvFldr(this);
	}

};


void testMessage();
