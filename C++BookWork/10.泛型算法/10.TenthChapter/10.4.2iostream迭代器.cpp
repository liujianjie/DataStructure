#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include <functional>
#include <iterator>
#include <fstream>
#include "Sales_item.h"
#include "Sales_data.h"
using namespace std;
using namespace std::placeholders;// ռλ���ռ�


void prints(vector<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
void prints(vector<string> con)
{
	for_each(con.begin(), con.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
void prints(list<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
/*
Ϊ������������ָ����д�Ķ�������
�����ĵ����������ļ�����β����IO���� ��β�������ֵһ����

// ��ȡ��������Ա
(*in).mem;
istream_iter->mem;// �����ʱ��

�������������Ҫ������������������ļ��� �е���֡�����ûˢ�£���֪����ôˢ��
*/
int main()
{

	int a;
	//istream_iterator<int> in_iter1(cin), in_end;
	//vector<int> v1;
	//while (in_iter1 != in_end) {
	//	v1.push_back(*in_iter1++);
	//}
	//prints(v1);

	ifstream infile("afile.txt");
	istream_iterator<string> in_iter2(infile),in_end2;// �Զ�ƥ���д�Ķ�������
	/*while (in_iter2 != in_end2) {
		cout << *in_iter2++ << endl;
	}*/
	vector<string> v2(in_iter2, in_end2);// ����Ҫ��
	prints(v2);
	// �÷�
	//istream_iterator<int> in_iter3(cin), in_end3;
	//vector<int> v3(in_iter3, in_end3);// ����Ҫ��
	//prints(v3);

	// ʹ���㷨������������
	//istream_iterator<int> in_iter4(cin), in_end4;
	//cout << accumulate(in_iter4, in_end4, 0) << endl;

	// ostream_iterator
	ostream_iterator<int> out_iter1(cout, " ");
	vector<int> v4{1,2,3,4,56};
	for (auto e : v4)
		out_iter1 = e;//��ֵ���������
	for (auto e : v4)
		*out_iter1 = e;//��ֵ���������
	for (auto e : v4)
		*out_iter1++ = e;//��ֵ���������
	cout << endl;

	copy(v4.begin(), v4.end(), out_iter1);// Ҫ��ֵ������Ҳ�����
	cout << endl;

	//istream_iterator<Sales_item> item_iter(cin), eof;
	//ostream_iterator<Sales_item> out_iter(cout, "\n");
	//Sales_item sum = *item_iter++;
	//while (item_iter != eof) 
	//{
	//	// item_iter->isbn() (*item_iter).isbn()
	//	if (item_iter->isbn() == sum.isbn()) {
	//		sum += *item_iter++;
	//	}
	//	else {
	//		out_iter = sum;
	//		sum = *item_iter++;
	//	}
	//}
	//out_iter = sum;//��ӡ���һ��
	 
	// ��ϰ10.30
	//istream_iterator<int> is_it1(cin),is_itend;
	ostream_iterator<int> ot_it1(cout, " ");
	//vector<int> v8(is_it1, is_itend);
	vector<int> v8{1,43,23,12,43,54,65};
	sort(v8.begin(), v8.end());
	prints(v8);
	copy(v8.begin(),v8.end(), ot_it1);

	// 
	vector<int> v9{ 1,43,43,23,32,12,23,12,43,54,65 };
	unique_copy(v9.begin(), v9.end(),ot_it1);

	// 
	/*istream_iterator<Sales_item> item_iter2(cin), item_itereof2;
	vector<Sales_item> ve1(item_iter2, item_itereof2);
	sort(ve1.begin(), ve1.end(), [](const Sales_item& s1, const Sales_item& s2) {return s1.isbn().size() < s2.isbn().size(); });*/
	// find �� accumulate ����ѽ

	ofstream ofile1("file1.txt");
	ofstream ofile2("file2.txt");

	ostream_iterator<int> ositem1(ofile1," "),ositem2(ofile2,"\n");

	ifstream ifile1("input.txt");
	istream_iterator<int> istorfile(ifile1),istorend;

	while (istorfile != istorend) {
		cout << *istorfile << endl;
		if (*istorfile % 2) {
			ositem1 = *istorfile++;
		}
		else {
			ositem2 = *istorfile++;
		}
	}
	cout << "����" << endl;
	cin.clear();
	cin >> a;
	return 0;
}

