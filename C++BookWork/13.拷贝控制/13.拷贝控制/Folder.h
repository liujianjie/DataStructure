#pragma once
#include <set>
#include <iostream>

using namespace std;
class Message;
class Folder
{
public:
	explicit Folder(){}
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void save(Message&);
	void remove(Message&);

	void addMsg(Message*);
	void remMsg(Message*);

	void debug_print();
private:
	set<Message*> messages;

	// ¹¤¾ßº¯Êý
	void add_to_Message(const Folder&);
	void remove_from_Message();
};

