#include "Message.h"



Message::Message(const Message& rhs):
	contents(rhs.contents),
	floders(rhs.floders)
{
	// �������ӵ��Ҳ���ڵ�folder��
	add_to_Folders(rhs);
}
Message& Message::operator=(const Message& rhs)
{
	// �ҵķ������ȿ���������ͬ�Ķ����ٿ�ͬһ���������޸�
	remove_from_Folders();//�ȴ���folder�д���������Ϣ�Ķ�ɾ��
	// ˳�����ң���Ϊ������Ҫ��floders
	contents = rhs.contents;
	floders = rhs.floders;
	//�ٽ��ұ���Ϣ���ڵ�folder������������
	add_to_Folders(rhs);

	// ��Ϊͬһ������Ļ�ͬһ��ַ��ͬһֵ�����ȼ���ôʲô��û�䣬��ɾ����Ϊ����
	// ����ɾ��ֻ����floders������ɾ�������ָ�룬��floders���ϱ���û��ɾ�������Կ��Լӻ���
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& f)
{
	floders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder& f)
{
	floders.erase(&f);
	f.remMsg(this);
}
void Message::addFolder(Folder* f)
{
	floders.insert(f);
}
void Message::removeFolder(Folder* f)
{
	floders.erase(f);
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.floders) {
		f->addMsg(this);
	}
}
void Message::remove_from_Folders()
{
	for (auto f : floders) {
		f->remMsg(this);
	}
}

void Message::swap(Message& lhs, Message &rhs)
{
	// 
	using std::swap;
	// ����� �Ҳ��floder������ɾ���Լ�
	for (auto f : lhs.floders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.floders) {
		f->remMsg(&rhs);
	}
	// ����
	swap(lhs.contents, rhs.contents);
	swap(lhs.floders, rhs.floders);// ���õ��Ǳ�׼���swap
	// ����ӻ���
	for (auto f : lhs.floders) {
		f->addMsg(&lhs);
	}
	for (auto f : rhs.floders) {
		f->addMsg(&rhs);
	}

}
// ��set����Ԫ�ؿ��ܻ��׳��쳣��Ҫ������ڴ棬�����׳�bad_alloc�ڴ�ľ�������δ���Ϊnoexcept
void Message::move_Folders(Message *m)
{
	floders = std::move(m->floders);
	for (auto f : floders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->floders.clear();
}
Message::Message(Message &&rhs):
	contents(std::move(rhs.contents))
{
	move_Folders(&rhs);
}
Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs) {
		remove_from_Folders();// ɾ��ԭ�еģ���ࣩ
		contents = std::move(contents);
		move_Folders(&rhs);// ͬ��Ҫɾ�Ҳ��������� ��Ϊ���ƶ�
	}
	return *this;
}