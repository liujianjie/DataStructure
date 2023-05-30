#include "ConstRef.h"

//ConstRef::ConstRef()
//{
//}
ConstRef::ConstRef(int ii) :  ci(ii), ri(i)
{
	// 如若赋值 错误
	i = ii;
	//ci = ii;// 不能给const赋值
	//ri = i;//  ri没有初始化
}

ConstRef::~ConstRef()
{
}
