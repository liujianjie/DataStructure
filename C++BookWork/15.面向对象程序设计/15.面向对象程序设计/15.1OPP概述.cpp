#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

/*
������
������������Ƶĺ���˼�������ݳ��󡢼̳кͶ�̬��
���ݳ��󣺽���Ľӿ���ʵ�ַ���
�̳У����Ƶ����Ͳ��������ƹ�ϵ��ģ
��̬�󶨣���һ���̶��Ϻ������Ƶ����͵����𣬶���ͳһ�ķ�ʽʹ�����ǵĶ���

һ���̳�
�̳У���ϵ��һ����๹��һ�ֲ�ι�ϵ�����࣬������

�麯������������Զ����ʺ�����İ汾��virtual��ͷ������������Ҳ���Զ���
�������б���ȷָ�����ĸ�����̳ж����ģ�һ��ð�� + ����˵���� + ����

������������麯�����¶����˾���Ҫ��������

������̬��
����ͬһ�δ���ֱ���Quote��Bulk_quote����
��̬����ʱ�ֱ���Ϊ����ʱ��
note��������ʹ�û�������� ��ָ�����һ���麯��ʱ��������̬��

*/

double print_total(ostream& os,
	const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() <<
		"# sold:" << n << "total due:" << ret << endl;
}
int main()
{
	int a;

	Quote basic;

	Bulk_quote bulk;

	print_total(cout, basic, 20);
	print_total(cout, bulk, 20);

	cin >> a;
	return 0;
}