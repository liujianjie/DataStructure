#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
/*
1.new 将内存分配和对象构造组合绑定了一起，delete将对象析构和内存释放组合了一起
2.希望内存分配和对象构造分离
3.并且列子，string被赋值了两次，一次默认初始化，一次赋值时

4.头文件memory中是一个模板需指定可以分配的对象类型
5.恰当的内存大小和对象位置

5.两个伴随算法，拷贝和填充
*/
int main()
{
	int a;
	allocator<string> alloc1;
	auto const p1 = alloc1.allocate(50);// 可以分配n个未初始化的string，分配了内存，但是未初始化未构造

	// 
	auto q1 = p1;// q1指向最后构造的元素之后的位置,p1指向开始位置
	alloc1.construct(q1++);
	alloc1.construct(q1++, 10, 'c');
	alloc1.construct(q1++, "hi");

	
	cout << *p1 << endl;
	//cout << *q1 << endl;// 指向未构造的内存 因为q1++了
	//alloc1.destroy(q1);// 还未构造
	// 删除
	while (q1 != p1) {
		alloc1.destroy(--q1);// 释放构造了的string，逆序，只能对构造了的进行destory
	}
	// 只是删除元素，还有内存存在，可以返回系统
	alloc1.deallocate(p1, 3);// 可以指定大小 最好为初始化内存大小，并且内存中的元素被删除

	vector<int> ve{ 1,2,3,4,5,6,7,8 };
	allocator<int> all2;
	auto p2 = all2.allocate(ve.size() * 2);
	auto q2 = uninitialized_copy(ve.begin(), ve.end(), p2);//目的位置，返回的是最后一个位置
	uninitialized_fill_n(q2, ve.size(), 42);//

	// 练习
	allocator<string> all3;
	auto strp = all3.allocate(100);
	auto strq = strp;
	string strs;
	while (cin >> strs && strs != "-1") {
		all3.construct(strq++, strs);
	}
	const size_t sizes = strq - strp;
	for (int i = 0; i < sizes; ++i) {
		cout << strp[i] << " ";
	}
	while (strq != strp) {
		all3.destroy(--strq);
	}
	// 这步很重要 将内存返回系统
	all3.deallocate(strp,100);

	cin >> a;
	return 0;
}
