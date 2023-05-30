#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
/*
1.new ���ڴ����Ͷ�������ϰ���һ��delete�������������ڴ��ͷ������һ��
2.ϣ���ڴ����Ͷ��������
3.�������ӣ�string����ֵ�����Σ�һ��Ĭ�ϳ�ʼ����һ�θ�ֵʱ

4.ͷ�ļ�memory����һ��ģ����ָ�����Է���Ķ�������
5.ǡ�����ڴ��С�Ͷ���λ��

5.���������㷨�����������
*/
int main()
{
	int a;
	allocator<string> alloc1;
	auto const p1 = alloc1.allocate(50);// ���Է���n��δ��ʼ����string���������ڴ棬����δ��ʼ��δ����

	// 
	auto q1 = p1;// q1ָ��������Ԫ��֮���λ��,p1ָ��ʼλ��
	alloc1.construct(q1++);
	alloc1.construct(q1++, 10, 'c');
	alloc1.construct(q1++, "hi");

	
	cout << *p1 << endl;
	//cout << *q1 << endl;// ָ��δ������ڴ� ��Ϊq1++��
	//alloc1.destroy(q1);// ��δ����
	// ɾ��
	while (q1 != p1) {
		alloc1.destroy(--q1);// �ͷŹ����˵�string������ֻ�ܶԹ����˵Ľ���destory
	}
	// ֻ��ɾ��Ԫ�أ������ڴ���ڣ����Է���ϵͳ
	alloc1.deallocate(p1, 3);// ����ָ����С ���Ϊ��ʼ���ڴ��С�������ڴ��е�Ԫ�ر�ɾ��

	vector<int> ve{ 1,2,3,4,5,6,7,8 };
	allocator<int> all2;
	auto p2 = all2.allocate(ve.size() * 2);
	auto q2 = uninitialized_copy(ve.begin(), ve.end(), p2);//Ŀ��λ�ã����ص������һ��λ��
	uninitialized_fill_n(q2, ve.size(), 42);//

	// ��ϰ
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
	// �ⲽ����Ҫ ���ڴ淵��ϵͳ
	all3.deallocate(strp,100);

	cin >> a;
	return 0;
}
