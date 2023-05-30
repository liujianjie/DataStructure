#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include <vector>
#include <memory>
#include "Disc_quote.h"

using namespace std;

/*
引出：
使用容器存放继承体系中的对象时，通常必须采用间接存储的方式
不允许再容器中保存不同类型的元素，所以不能存储继承关系的多种类型的对象放在容器中。

如：
若vector中保存bulk_quote对象，无法把quote放置在容器中
若vector中保存quote对象，把bulk_quote对象存放的话，只是存放bulk_qote对象中基类部分，而派生类部分会切掉，静态类型为quote，则执行它的net_price

二、在容器中放置（智能）指针而非对象
存放基类的指针（更好的选择是智能指针）动态类型可能是基类或派生类

派生类的智能指针也能转换成基类的智能指针
*/


int main()
{
	int a;
	vector<Quote> ve1;
	Bulk_quote bk("aaa",20,3,0.5);
	ve1.push_back(bk);
	Quote *qt1 = &ve1.front();
	cout << qt1->net_price(4) << endl;
	cout << bk.net_price(4) << endl;

	cout << "------" << endl;
	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Quote>("0-12-123", 50));
	basket.push_back(make_shared<Bulk_quote>("0-12321", 50, 10, .25));
	cout << basket.front()->net_price(15) << endl;
	cout << basket.back()->net_price(15) << endl;
	
	vector<Quote> ve2;
	ve2.push_back(Bulk_quote("aaa", 20, 3, 0.5));
	ve2.push_back(Bulk_quote("aaa", 40, 3, 0.5));
	ve2.push_back(Bulk_quote("aaa", 30, 3, 0.5));
	ve2.push_back(Bulk_quote("aaa", 50, 3, 0.5));
	double sum = 0;
	for (auto be : ve2) {
		sum += be.net_price(4);
	}
	cout << sum << endl;

	vector<shared_ptr<Quote>> ve3;
	//ve3.push_back(Bulk_quote("aaa", 20, 3, 0.5));// 不可
	ve3.push_back(make_shared<Bulk_quote>("aaa", 20, 3, 0.5));
	ve3.push_back(make_shared<Bulk_quote>("aaa", 40, 3, 0.5));
	ve3.push_back(make_shared<Bulk_quote>("aaa", 30, 3, 0.5));
	ve3.push_back(make_shared<Bulk_quote>("aaa", 50, 3, 0.5));
	 sum = 0;
	for (auto be : ve3) {
		sum += be->net_price(4);
	}
	cout << sum << endl;
	// 练习
	/*
	15.28:ok
	15.29:ok 因为动态类型
	*/
	cin >> a;
	return 0;
}
