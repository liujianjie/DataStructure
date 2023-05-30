#include "Folder.h"
#include "Message.h"


//Folder::Folder()
//{
//}
// ��Ҫ����ÿ��rhsӵ�е�msg Ҳ��Ҫ��ӵ������
Folder::Folder(const Folder& rhs):
	messages(rhs.messages)
{
	add_to_Message(rhs);
}
Folder& Folder::operator=(const Folder& rhs)
{
	// �Ը�ֵҲ�ܴ�����ɾ����message���Լ�������ӻ��Լ�
	// ��Ҫɾ������message�����е��Լ�
	remove_from_Message();
	// ����
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