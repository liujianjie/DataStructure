#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include <algorithm>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"
#include "Foo.h"
using namespace std;
/*
��ƪ������
������Щ������Ԫ��˳����㷨һ��ʹ�õ��࣬����swap����Ҫ�ġ�
����Լ�������swap��ʹ�����Զ���汾�������㷨��ʹ�ñ�׼�����swap

��׼�����swap�ᴦ��һ�����󣬴���һ����ʱ�ĸ�������ô�ͻᵼ��string�������Σ������Ӧ��Ҫ����Ϊ��ֵ�Ż�ѣ��ѵ�Ĭ�ϵ�swap�Ǵ���Ϊֵ��
���ǿ����Լ�����swap������ָ�����һ��������

swap�����Ǳ�Ҫ�ġ����ڷ�������Դ����(������ָ�����͵ĳ�Ա������Ϊ��ֵ)������swap��һ�ֺ���Ҫ���Ż��ֶ�

����swap����Ӧ�õ���swap��������std����swap
���һ����ĳ�Ա���Լ���swap������ʹ��std::swap�Ǵ���ģ�ǰ��std����swap��Ϊ���ó�Աû���Լ���swap�������ñ�׼���swap��
������Լ���swap�͵��ó�Ա�Լ���swap

ƥ��̶����ȱ�׼���swap,210ҳ

�����ڸ�ֵ�������ʹ��swap
�����������ļ�����
��������Ҳ��һ���������н���
��֤�쳣��ȫ�ķ���Ҳ��ԭ���ĸ�ֵ�����ʵ��һ����
�Զ����쳣��ȫ�ģ���������ȷ�����Ը�ֵ
*/
// 13.3

inline
void swap(Foo &lhs, Foo &rhs) {
	cout << "swap(Foo &lhs, Foo &rhs)" << endl;
	using std::swap;
	swap(lhs.h, rhs.h);
	// ����foo�ĳ�Ա
}
int main() {

	int aa;
	
	HasPtr hs1("hs1"),hs2("hs2"); 

	Foo f1(hs1), f2(hs2);
	swap(f1,f2);
	cout << "f1��pss��" << f1.getHas().getPss() << endl;
	cout << "f2��pss��" << f2.getHas().getPss() << endl;

	// ��ϰ
	/*
	��������ƥ�䣬ʵ�ֵķ�������һ��
	*/
	/*
	��ʹ��swapʱ���Ϳ�ͷ˵�ģ�������Ԫ��˳����㷨ʹ�õ�ʱ��
	*/
	cout << "-------" << endl;
	vector<HasPtr> ve;
	ve.push_back((HasPtr)("123"));
	ve.push_back((HasPtr)("1234"));
	ve.push_back((HasPtr)("122323"));
	ve.push_back((HasPtr)("13"));
	ve.push_back((HasPtr)("1"));
	sort(ve.begin(), ve.end());// ��֪����ôд, ͻȻ�ֿ�����

	for (auto it : ve) {
		cout << it.getPss() << endl;
	}
	cout << endl;
	
	/*
	��ָ��汾 ��������ڴ棬��˲���
	*/

	std::cin >> aa;
	return 0;
}