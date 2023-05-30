#include "Message.h"



Message::Message(const Message& rhs):
	contents(rhs.contents),
	floders(rhs.floders)
{
	// 将左侧添加到右侧存在的folder中
	add_to_Folders(rhs);
}
Message& Message::operator=(const Message& rhs)
{
	// 我的方法，先看做两个不同的对象，再看同一个对象处理修改
	remove_from_Folders();//先处理folder中存在这条消息的都删除
	// 顺序不能乱，因为必须先要有floders
	contents = rhs.contents;
	floders = rhs.floders;
	//再将右边消息所在的folder集合中添加这个
	add_to_Folders(rhs);

	// 因为同一个对象的话同一地址和同一值，若先加那么什么都没变，再删除则为空了
	// 若先删，只是在floders集合中删除了这个指针，而floders集合本身没有删除，所以可以加回来
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
	// 将左侧 右侧的floder集合中删除自己
	for (auto f : lhs.floders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.floders) {
		f->remMsg(&rhs);
	}
	// 交换
	swap(lhs.contents, rhs.contents);
	swap(lhs.floders, rhs.floders);// 调用的是标准库的swap
	// 再添加回来
	for (auto f : lhs.floders) {
		f->addMsg(&lhs);
	}
	for (auto f : rhs.floders) {
		f->addMsg(&rhs);
	}

}
// 向set插入元素可能会抛出异常，要求分配内存，可能抛出bad_alloc内存耗尽，所以未标记为noexcept
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
		remove_from_Folders();// 删掉原有的（左侧）
		contents = std::move(contents);
		move_Folders(&rhs);// 同样要删右侧在添加左侧 因为是移动
	}
	return *this;
}