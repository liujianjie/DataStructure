#include <iostream>
#include <fstream>

using namespace std;

/*
因为设备的写操作耗时，所以操作系统允许多个输出操作组合为单一的设备写操作提供性能提升

缓冲刷新
1.程序正常结束 main的return
2.缓冲区满了
3.操作符endl
4.unitbuf
5.对关联的流操作
*/
void testnull()
{
	cout << "testnull()" << endl;
}
void testnull(ostream* v) 
{
	cout << "testnull(int v)" << endl;
}
int main()
{
	int a;
	cout << "hi" << endl;// 换行
	cout << "hi" << flush;//刷新缓冲区
	cout << "hi" << ends;// 多了空字符

	cout << unitbuf;
	cout << "...";
	cout << "asdf";
	cout << "zxvcx";
	cout << nounitbuf;
	cout << "qweq";
	cout << "...";
	// 程序崩溃，输出缓冲区不会被刷新

	// 关联输入和输出流
	testnull(nullptr);

	cin.tie(&cout);// cin与cout关联
	ostream *old_tie = cin.tie(nullptr);//  cin不与谁关联，但是还是会返回先前关联的
	cin.tie(&cerr);// cin与cerr关联
	cin.tie(old_tie);// cin再与cout关联
	// 每个流最多同时关联到一个流, 但多个流可以用时关联到同一个ostream
	cin.tie(&cerr);// 会解开先前的关联吧




	cin >> a;
	return 0;
}