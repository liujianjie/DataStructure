#include "ConstRef.h"

//ConstRef::ConstRef()
//{
//}
ConstRef::ConstRef(int ii) :  ci(ii), ri(i)
{
	// ������ֵ ����
	i = ii;
	//ci = ii;// ���ܸ�const��ֵ
	//ri = i;//  riû�г�ʼ��
}

ConstRef::~ConstRef()
{
}
