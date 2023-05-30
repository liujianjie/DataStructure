#include <iostream>
#include <string>
#include "TestStruct.h"
#include <vector>

using namespace std;
int main()
{
	int getchar = 0;

	cout << getchar << endl;

	int ival;

	ival + 5;
	;
	// 4.13 求值顺序
	int i = 0;
	cout << i << " " << ++i << endl;
	int i2 = 1024;
	int k = -i;
	bool b = true;
	bool bb2 = -b;
	cout << (bool)bb2 << endl;

	//溢出
	short st = 32767;
	cout << st + 2 << endl;
	int it = 2147483647;
	cout << it + 1 << endl;

	//
	int m = 21, n = -5;
	cout << m%n << endl;
	m = -21, n = -8;
	cout << m%n << endl;
	m = -21, n = 8;
	cout << m%n << endl;

	// 4.3逻辑运算与关系运算符
	int ival2, *pval2;
	//ival2 = pval2 = 0;
	string s1, s2;
	s1 = s2 = "333";
	cout << s1 << endl;

	// 4.5递增与递减
	int fivei = 0;
	cout << fivei++ << endl;
	cout << ++fivei << endl;

	// 算混用解引用与递增运算符，因为左值对象和fpival对象不相同，所以不会有混乱关系，
	int *fpival = &fivei;
	int fivei2 = *fpival++;
	cout << fivei2 << endl; // 2

	// 这个将存在混乱关系，到底是 *(recl+1) = toupper(*recl);(先求右侧的值) 还是 *（recl) = toupper(*beg)(先求左侧的值);
	char c1 = 'a';
	char *rec1 = &c1;
	/**rec1 = toupper(*rec1++);*/
	*rec1 = toupper(*rec1);
	cout << *rec1 << endl;
	*(rec1) = toupper(*rec1 + 1);
	cout << *rec1 << endl;

	// 4.6 成员访问运算符
	string str = "asdfasdf", *p = &str;
	size_t nn = str.size();
	// 下面两个等价
	nn = (*p).size();
	nn = p->size();
	cout << nn << endl;


	//4.7条件运算符 ?:
	int fourgrade = 70;
	string foursoutpr = fourgrade > 60 ? "pass" : "fail";
	cout << foursoutpr << " ";
	//嵌套的
	fourgrade = 50;
	string foursoutpr2 = fourgrade > 90 ? "high" : fourgrade > 60 ? "pass" : "fail";
	cout << foursoutpr2;
	cout << endl;

	//与cout 混用 因为条件运算符的优先级很低
	cout << (fourgrade > 60 ? "pass" : "fail") << endl;
	cout << (fourgrade > 60) ? "pass" : "fail";//  << endl 得省略 好像 endl 不接受一个 字面值？？
	//cout << fourgrade > 60 ? "pass" : "fail";// error 试图比较 cout和60

	// 第二句 等价 cout<<(fourgrade > 60) 输出1 或 0  然后 ? 后面的字符串产生对应的字面值
	// 第三句 不可，因为 cout<<fourgrade 先输出four.. 然后再让cout对象与 60 比 cout > 60 ?，而cout是无>重载运算符的

	// 4.8位运算符
	int fei = 9;
	cout << (fei << 3) << endl;//9 * 2的3次方
	cout << (fei >> 2) << endl;//9 / 2的2次方

	unsigned char bitchar = 0233;// 0 开头为八进制数 155
	cout << (bitchar << 2) << endl;// 155 * 2的2次方 
	cout << bitchar << 2 << endl;//得用括号括起来 这样不行。

	//位求反
	unsigned char bits = 0227; // 10010111
	cout << (~bits) << endl;// 111111111111111111111111 01101000

	// 位与 位或  位异或 在两个运算符上
	unsigned char b1 = 0145; // 01100101
	unsigned char b2 = 0257; // 10101111
	cout << (b1 & b2) << endl;// 00100101
	cout << (b1 | b2) << endl;// 11101111
	cout << (b1 ^ b2) << endl;// 11001010

	//  使用位运算符例子
	unsigned long quiz1 = 0;
	1UL << 27;// 生成一个值 只有第27位为1，原理 将值为1的位向左移了27位补0所以是第27位为1
	// 为了更新quiz1的值
	quiz1 |= 1UL << 27;// |= 为 quiz1 = quiz | 1UL<<27
	// W未通过 置为0
	quiz1 &= ~(1UL<<27);//~ 使27为0其它为1，后又加了个& 使变了的 又恢复了原样
	// 查看27位是否为1
	bool status = quiz1 &(1UL << 27);
	cout << status << endl;
	quiz1 |= 1UL << 27;
	status = quiz1 &(1UL << 27);
	cout << status << endl;

	// 移位运算符比算术运算符低 比关系 赋值 条件运算低

	// sizeof 运算符
	cout << "sizeof" << endl;
	Sals_data datas, *salsDatap;
	cout << sizeof(Sals_data) << endl;// Sals_data 类型的对象所占的空间大小
	cout << sizeof datas << endl;// data的类型的大小，即 sizeof(Sals_data)
	cout << sizeof salsDatap << endl;// 指针所占的空间大小
	cout << sizeof *salsDatap << endl;// p所指类型的空间大小，即sizeof（Sals_data) 
	cout << sizeof datas.reven << endl;// Sals_data 的reven成员对应得类型的大小
	cout << sizeof Sals_data::reven << endl;// 另一种获取reven大小的方式
	cout << sizeof Sals_data::bookNo << endl;
	cout << sizeof Sals_data::sold << endl;
	// sizeof 满足右结合律 所以等价 sizeof（*p),并且不实际运算值，指针是无效 未定义的也没有影响

	// 4.10逗号运算符
	vector<int> ivec = {2,5,6,7,3,4,5,9};
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0;
		ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;

	for (auto i = 0; i != ivec.size(); ++i)
		cout << ivec[i];
	cout << endl;

	cin >> getchar;
	return -1;
}