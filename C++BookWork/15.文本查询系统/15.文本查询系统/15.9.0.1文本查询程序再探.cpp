#include <iostream>
#include <vector>
#include <memory>
#include <regex>

using namespace std;
/*
����Ӧ�ý����ֲ�ͬ�Ĳ�ѯ��ģ���໥�������࣬��Щ�๲��һ���������ࣺ
WordQuery //Daddy ���ʲ�ѯ
NoteQuery// ~Alice �߼���
OrQuery// hair | Alice �߼���
AndQuery // hair & Alice �߼���

ֻ��������������
eval,����һ��TextQuery���󲢷���һ��QueryResult��eval����ʹ�ø�����TextQuery���������֮ƥ�����
rep,���ػ�����ѯ��string��ʾ��ʽ��eval����ʹ��rep����һ����ʾƥ������QueryResult����������ʹ��rep��ӡ��ѯ���ʽ

1.�������
1) �����������ʾ�ӿڣ�Query_base,eval rep���崿�麯��
2��wordquery,notequeryֱ�Ӵ�query_base������AndQuery OrQuery��Ҫһ��BinaryQuery����������������󣬵�ҲҪ����Query_base

2.����ι�ϵ�����ڽӿ�����
1) ����һ���ӿ���Query�������������̳���ϵ����һ��Query_baseָ�룬�󶨵����������
2����eval��rep ��������������
3������3���������һ������string�Ĺ��캯������Щ������̬����һ���µ�Query_base���������
(1) &���������һ���󶨵��µ�AndQuery�����ϵ�Query����
(2) |���������һ���󶨵��µ�OrQuery�����ϵ�Query����
(3) ~������������������������NotQuery��������������
(4) string���캯������������WordQuery����

Query q = Query("fiery") & Query("bird") | Query("wind");

������query�����������

3.�����Щ��Ĺ�������

*/
using namespace regex_constants;
int main()
{
	int a;
	// ��ϰ
	/*
	15.31�� ok
	   s1
a,b	|:
	      s2
	   &
	      ~ s3

		  s3
		&
		  s4
c   |
		  s2
		&
		  s1

	*/
	cin >> a;
	return 0;
}
