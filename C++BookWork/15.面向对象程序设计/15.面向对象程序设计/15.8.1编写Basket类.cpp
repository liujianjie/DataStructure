#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include <vector>
#include <memory>
#include "Disc_quote.h"
#include "Basket.h"

using namespace std;

/*
������
�޷�ֱ��ʹ�ö��������������̡�����ʹ��ָ������á�
��ָ������ӳ���ĸ����ԣ����Ծ�������һЩ�����������������ָ������

����һ����ʾ����������
����ϸ�ڣ�
items.upper_bound(*be))��upper_bound ͬ���ؼ��ֵ���һλ�ã�Ҫ��ȡ�ؼ��֣�����������õõ�����Ķ���ֵ
**be ��һ��quote����*be�õ�����ָ�룬**be�õ�������һ����̬�Ķ���
count,ͳ���ж��ٸ�Ԫ�صĽ�ֵ��ͬ

��������ָ��
basket���û�����Ҫ����̬�ڴ档����basket���û�������̬�ڴ棬������basket������add_item�Ķ��壬��������̬�ڴ�

���¶����void add_item(const Quote &sale);// ���������Ķ���
	void add_item(Quote &&sale);// �ƶ������Ķ���
���Ǵ���һ�����⣬������ʱ��
items.insert(shared_ptr<Quote>(new Quote(sale)));
����new Quote(sale),��sale��bulk_quote���ͣ�ֻ�ǰ�sale�еĻ��ಿ�ָ�Quote�������ܻ�ȡһ��bulk_quote��ָ�룬�ᱻ�е�һ����

����ģ���鿽��
Ϊ�˽���������⣬��Quote�����һ���麯�����ú�����ȡһ�ݵ�ǰ����Ŀ���

��Ҫ������ֵ����ֵ�汾����ֵ�汾����Ȼsale����ֵ�������ͣ�����sale��������ֵ��������Ҫstd::move����һ����ֵ���ð󶨵�sale��

sale�Ķ�̬���;�����������quote��������bulk_quote���������ۿ��������ƶ���clone������һ���·�������ָ�룬��shared_ptr�󶨵����
�����ϣ�Ȼ��insert��
shared_ptr֧������������������ת��������shared_ptr<Quote>���԰󶨵�Bulk_quote*��
*/


int main()
{
	int a;
	Basket bs;
	//bs.add_item(make_shared<Bulk_quote>("aaa", 20, 3, 0.5));
	//bs.add_item(make_shared<Bulk_quote>("aaa", 20, 3, 0.5));
	//bs.add_item(make_shared<Bulk_quote>("aaa", 20, 3, 0.5));
	//bs.add_item(make_shared<Bulk_quote>("aaa", 20, 3, 0.5));
	//bs.add_item(make_shared<Bulk_quote>("aaa1", 20, 3, 0.5));
	//bs.add_item(make_shared<Bulk_quote>("aaa1", 20, 3, 0.5));
	//bs.add_item(make_shared<Bulk_quote>("aaa2", 20, 3, 0.5));
	//bs.add_item(make_shared<Bulk_quote>("aaa2", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa1", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa1", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa2", 20, 3, 0.5));
	bs.add_item(Bulk_quote("aaa2", 20, 3, 0.5));
	cout << bs.total_receipt(cout) << endl;
	// ��ϰ
	/*
	*/
	cin >> a;
	return 0;
}
