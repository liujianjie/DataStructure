#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// 1.void ��ʽreturn ʹ�����˳�
void swap(int a,int b) 
{
	if (a == b) {
		return;
	}
	cout << "swap ing" << endl;
	return;
}
int swap2(int a, int b) 
{
	if (a < b) {
		return 1;
	}
}
int& swap3(int a, int b) {
	return a > b ? a : b;
}
const string &shorterString(const string &s1, const string &s2) 
{
	return s1.size() <= s2.size() ? s1 : s2;
}
const string &mainp() 
{
	string ret;
	// ��ĳ�ַ�ʽ�ı�һ��ret
	if (!ret.empty())
		return ret;// error ���ؾֲ����������
	else
		return "Empty";// error ��һ���ֲ���ʱ��

}
char &get_val(string &str, string::size_type ix) {

	return str[ix];
}

vector<string> process() 
{
	string expected = "runtime", actual = "westtime";
	if (expected.empty())
		return{};
	else if (expected == actual)
		return{ "FunctionX","OKAY" };
	else
		return{ "functionX",expected,actual };

}
int factorial(int val) 
{
	if (val > 1)
		return val * factorial(val - 1);	

		return 1;
}
int main() 
{
	int getchar;

	// 1.�޷���ֵ����
	swap(3,3);
	// 6.3.2�з���ֵ����
	// return������ �붨���������ͬ��������ʽ��ת���ɣ������ĺ�����Ҫֻ��ͨ��һ����Ч��return����˳���������Ҫû�������Ŀ�����
	// �����ˣ��������޷����ִ˴����ڿ�������û��return���ֵ��
	int get = swap2(5,2);
	cout << get << endl;

	// ����ֵ����α����صģ��ǿ����Ķ��� ���� һ����ʱ�������Կ���ʹ������
	get = swap3(5, 2);
	cout << get << endl;

	// ������Ҫ���ؾֲ���������û�ָ��
	// ��Ϊmainp���ؾֲ����󣬺�������ʱ����Ѿ������ˣ�����mainp������δ�����ֵ��������δ�������Ϊ��ָ��Ҳ�ǲ����Ǿֲ�����
	//string s2 = mainp();
	//cout << s2 << endl;

	// �ģ����������͵ĺ����͵��������
	// ��������������ȼ���=�����������ĺͼ�ͷ����� ��ͬ�����ҷ��������ɡ�
	// ���ԣ���������ָ�룬���û���Ķ������Ǿ���ʹ�ú������õĽ�����ʽ������ĳ�Ա
	string fours1 = "sdfsdgdsf";
	string fours2 = "sdfdsfgdsfsd";
	auto sz = shorterString(fours1, fours2).size();
	cout << sz << endl;

	// �壬���÷�����ֵ
	// ����������һ����ֵ����������Ϊ��ֵ��ֻҪ���Ƿǳ������õĺ�����
	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A';
	cout << s << endl;

	// ������س��������򲻿�������
	//shorterString("adf","dfhsd") = "X";

	// �б��ʼ������ֵ
	vector<string> ve = process();
	for (string s : ve)
		cout << s << " ";
	cout << endl;

	// ������main�ķ���ֵ��0��ʾ�ɹ���������ʾ������˼���������ʽ�����

	// �ݹ�
	//main(); ��֣������Լ������Լ�main
	cout << factorial(5) << endl;

	cin >> getchar;
	//return EXIT_FAILURE;
	return EXIT_SUCCESS;
}