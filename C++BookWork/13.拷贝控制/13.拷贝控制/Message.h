#pragma once
#include <set>
#include <string>
#include "Folder.h"
#include <vector>

using namespace std;
class Message
{
	friend class Folder;
public:
	explicit Message(const string &st = string()) :
		contents(st)
	{
	}
	Message(const Message&);
	Message& operator=(const Message&);

	~Message();

	void save(Folder&);
	void remove(Folder&);

	void swap(Message& lhs, Message &rhs);

	void addFolder(Folder*);
	void removeFolder(Folder*);

	// 移动
	void move_Folders(Message *m);
	Message(Message&&);
	Message& operator=(Message &&);
private:
	string contents;
	set<Folder*> floders;
	// 工具函数
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

