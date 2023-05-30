#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "StrBlob.h"
#include "StrBloPtr.h"

using namespace std;



/*
���壺����ͬ���͵���һ���������ǰ����ֵʱ�����ǲ��ǳ�ʼ�������Ѿ�������˵ĺ�����ͬ���͵���һ������ ��ֵ��Ҳ����=��ֵ�����

д����
����=�������һ���������ͺ�һ�������б�
����һ��ָ�������������������(*this)
�����б���һ��������������ͬ���ͣ������ò�����const���Ҳ����������Ϊ��ʽ��������

��ֵ��������壺������=��������������һ����Ա����������һ��ָ�������������������

*/
int main() {

	int a;
	
	// ��ϰ
	/*13.6��������=��������������һ����Ա����������һ��ָ������������������� ��ͬ���Ͷ��󸳸�����������
	��=ʱ
	���Ҳ���������static�ĳ�Ա������������������
	������û�ж����ʱ��
	*/
	/*
	13.7
	���úϳɵĿ������캯��ѽ
	*/
	// ������ֵstrblob ����һ���µ�
	StrBlob sbb1, sbb2;
	//shared_ptr < vector<string>> data = make_shared < vector<string>>();
	sbb2.data = make_shared < vector<string>>();
	(*sbb2.data).push_back("1");
	(*sbb2.data).push_back("2");
	(*sbb2.data).push_back("3");
	cout << (*sbb2.data).size() << endl;
	sbb1 = sbb2;
	cout << (*sbb1.data).size() << endl;
	cout << "�����˹����ˣ�" << sbb1.data.use_count() << endl;
	cout << "�����˹����ˣ�" << sbb2.data.use_count() << endl;

	// ������ֵStrBloPtr ����ֻ��һ��Ӧ���ǵ�ַ
	StrBlob sbb3, sbb4;
	sbb4.data = make_shared < vector<string>>();
	(*sbb4.data).push_back("1");
	(*sbb4.data).push_back("2");
	(*sbb4.data).push_back("3");
	StrBloPtr sbp1, sbp2(sbb4);
	sbp1 = sbp2;
	cout << "sbb4:" << sbb4.data.use_count() << endl;
	cout << "strbloptr:" << sbp1.getWptr().use_count() << endl;
	cout << "strbloptr:" << sbp2.getWptr().use_count() << endl;
	cout << "sbp1:" << (sbp1.getWptr().lock()->size()) << endl;
	cout << "sbp2:" << (sbp1.getWptr().lock()->size()) << endl;
	cin >> a;
	return 0;
}