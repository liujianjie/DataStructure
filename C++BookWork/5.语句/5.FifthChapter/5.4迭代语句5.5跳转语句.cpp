#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int getchar;
	// while
	//int j = 3;
	/*while (int jj = 4) {
		cout << "has this caozuo��d" << jj<< endl;
		jj = 0;
	}*/
	//int i;
	//vector<int> v;
	//while (cin >> i  && i != 0)
	//{
	//	v.push_back(i);
	//}
	//auto begin = v.begin();
	//while (begin != v.end() && *begin >= 0) {
	//	cout << *begin++ <<" ";
	//}
	//if (begin == v.end())
	//	cout << "no zero" << endl;


	//// ��ͳ��for���
	//string consforstr = "adflkjlkcxzvzlkj sadf sdf ";
	//for (decltype(consforstr.size()) index = 0;index != consforstr.size() && !isspace(consforstr[index]); ++index) 
	//{
	//	consforstr[index] = toupper(consforstr[index]);
	//}
	//// ��ͷ���ֶ��ض���
	//for (decltype(consforstr.size()) index = 0,size = consforstr.size(); index != size && !isspace(consforstr[index]); ++index)
	//{
	//	consforstr[index] = toupper(consforstr[index]);
	//}
	//// forѭ��ʡ�Բ��� begin����������
	//begin = v.begin();
	//for (; begin != v.end() && *begin >= 0;) {
	//	cout << *begin++ << "s ";
	//}
	//cout << consforstr << endl;

	vector<int> vecs;
	//for (int i; cin >> i;)
		//v.push_back(i);

	// 5.4.3 ��Χfor���
	vector<int> fivefortv = { 0,1,2,3,4,5,6,7,8,9 };
	// ��Χ�����������������ͣ��������ܶ�Ԫ��ִ��д����
	for (auto &r : fivefortv) {
		r *= 2;
		cout << r << '\t';
		//fivefortv.pop_back();
	}
	// ����ô�ͳfor
	for (auto beg = fivefortv.begin(), end = fivefortv.end(); beg != end; ++beg) {
		// �������������Ͳſɲ��������Ԫ��
		auto &r = *beg;
		r *= 2;
		//fivefortv.push_back(10);
		//fivefortv.pop_back
	}
	/*
		ǰ��p90˵����ͨ����Χfor����vector����Ԫ�أ���Ϊ��for����ܣ�Ԥ����end()��ֵ��
		һ����ӻ�ɾ����end��������	�����Ч��
		�����»ᱨ��
	*/

	// 5.4.4 do while
	//do{

	//} while(int is = get_foo());
	/*string fivefourf;
	int val1, val2;
	do {
		cout << "enter two values\n";
		cin >> val1 >> val2;
		cout << val1 + val2 << '\n';
		cout << "do you want again?yes/no\n";
		cin >> fivefourf;
	} while (fivefourf[0] != 'n' && !fivefourf.empty());*/

	// continue switch��ֻ�ܵ�Ƕ�ײ�����
	int fivcs = 4;
	/*switch (fivcs)
	{
	default:
		continue;
		break;
	}*/

	// goto���
	goto label;
	label:cout << "goto label out str" << endl;

	goto labels;
	int fffix = 10;
labels: fffix = 42;

	// �������һ���Ѿ�ִ�еĶ����ǺϷ��ģ���ζ��ϵͳ�����ٸñ�����Ȼ�����´�����
	/*begin:
	int sz = -20;
		
	if (sz < 0) {
		sz = -4;
		cout << sz << endl;
		goto begin;
	}*/

	cin >> getchar;
	return 0;
}
int get_foo() 
{
	return 9;
}