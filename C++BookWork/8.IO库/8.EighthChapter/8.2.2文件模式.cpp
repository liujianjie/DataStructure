#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
ÿ��������һ���������ļ�ģʽ������ָ�����ʹ���ļ�
*/

int main()
{
	int a;
	fstream fs1("file1.txt");// Ĭ����inģʽ��

	// ofstreamĬ��out��ֻҪout�˾ͻ�Ĭ��ָ��trunc������ʾָ��app��in
	ofstream out1("file2.txt");// out trunc
	ofstream out2("file3.txt", ofstream::out);// out trunc
	ofstream out3("file4.txt", ofstream::out | ofstream::trunc);// out trunc

	ofstream out4("file4.txt", ofstream::app);
	ofstream out5("file5.txt", ofstream::out | ofstream::app);

	// ÿ��openʱ����ȷ���ļ�ģʽ
	ofstream out6;
	out6.open("file6.txt");
	out6.close();
	out6.open("file7.txt",ofstream::app);
	out6.close();

	ofstream of5("out1.txt", ofstream::app);
	vector<string> v3{ "word","vector","alholic","night" };
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		of5 << *beg << " ";
	}
	of5 << endl;// �Ỻ��

	cin >> a;
	return 0;
}