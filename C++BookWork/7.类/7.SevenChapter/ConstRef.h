#ifndef CONSTREF_H
#define CONSTREF_H

class ConstRef
{
public:
	//ConstRef();
	~ConstRef();
	ConstRef(int ii);
private:

	// 7.5.1 ���캯����ʼֵ�б�
	int i;
	const int ci;
	int &ri;
};
#endif // CONSTREF_H
