#include "Folder.h"
#include "Message.h"


//Folder::Folder()
//{
//}
// 需要遍历每个rhs拥有的msg 也需要添加到左侧中
Folder::Folder(const Folder& rhs):
	messages(rhs.messages)
{
	add_to_Message(rhs);
}
Folder& Folder::operator=(const Folder& rhs)
{
	// 自赋值也能处理，先删除在message的自己，再添加回自己
	// 需要删除左侧的message集和中的自己
	remove_from_Message();
	// 拷贝
	messages = rhs.messages;
	add_to_Message(rhs);
	return *this;
}

Folder::~Folder()
{
	remove_from_Message();
}

void Folder::save(Message& m)
{
	messages.insert(&m);
	m.addFolder(this);
}
void Folder::remove(Message& m)
{
	messages.erase(&m);
	m.removeFolder(this);
}

void Folder::addMsg(Message* m)
{
	messages.insert(m);
}
void Folder::remMsg(Message* m)
{
	messages.erase(m);
}
void Folder::add_to_Message(const Folder& fl)
{
	for (auto m : fl.messages) {
		m->addFolder(this);
	}
}
void Folder::remove_from_Message()
{
	for (auto m : messages) {
		m->removeFolder(this);
	}
}

void Folder::debug_print()
{
	cerr << "Folder contains" << messages.size() << "messages" << endl;
	int ctr = 1;
	for (auto m : messages) {
		cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
	}
}