#ifndef CONSTREF_H
#define CONSTREF_H

class ConstRef
{
public:
	//ConstRef();
	~ConstRef();
	ConstRef(int ii);
private:

	// 7.5.1 构造函数初始值列表
	int i;
	const int ci;
	int &ri;
};
#endif // CONSTREF_H
