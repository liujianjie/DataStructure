#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	// 5.3;
	int getchar;

	int i = 1;

	// ��Ҳ�У� ����������
	if (int j = 0)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	// 5.3 if-else 6���ȼ�
	const vector<string> scores = {"F","D", "C", "B", "A", "A++"};

	int grade;
	cin >> grade;
	string lettergrade;
	if (grade < 60)
		lettergrade = scores[0];
	else {
		lettergrade = scores[(grade - 50) / 10];// �ǳ���10 ����100
		if (grade != 100) {
			if (grade % 10 > 7)
				lettergrade += '+';
			else if (grade % 10 < 3)
				lettergrade += '-';
		}
	}
	cout << lettergrade << endl;
	lettergrade = scores[(grade - 50) / 10];// �ǳ���10 ����100
	// ����else
	if (grade % 10 >= 3)
		if (grade % 10 > 7)
			lettergrade += '+';
		else
			lettergrade += '-';
	cout << lettergrade << endl;

	// �û����ſ���ִ��·��
	if (grade % 10 >= 3) {
		if (grade % 10 > 7)
			lettergrade += '+';
	}
	else
		lettergrade += '-';

	// 5.3.2 switch���
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin >> ch && ch != '0') {
		switch (ch)
		{
		case 'a':
			++aCnt;
			break;
		case 'e' :
			++eCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
		default:
			break;
		}
	}
	cout << "a: \t" << aCnt << "\n"
		<< "e: \t" << eCnt << "\n"
		<< "i: \t" << iCnt << "\n"
		<< "o: \t" << oCnt << "\n"
		<< "u: \t" << uCnt << "\n";
	// ��Ҳ�У�
	switch (1)
	{
	
	}
	// ����˵case��ǩ���������γ������ʽ��, Ŷ 1�ǳ���
	int ival = 42;
	/*switch (ch)
	{
	case 3.14:
	case ival: error
	default:
		break;
	}*/

	// switch�ڲ��ı�������
	bool flag = true;
	/* ���case��ͬһ�������򣬵��ǵ�int ival = 0,���������Ϊ��ʾ��ʼ����
		�����е���ʱ�Ÿ��踳ֵ������ֱ��ֱ������falsecase�в���ʹ��ival���ᵼ�´�����ʽ��ʼ��Ҳ���С���string��int jval������ʽ��ʼ��*/
	string files_na;
	cout << files_na << endl;
	switch (flag)
	{
	case true:
		//string file_namesss; error ��ʽ��ʼ��
		//int ival = 0; �������������󣬽�����case��ǩival�ĳ�ʼ����������ʾ��ʼ��
		int jval;// δ��ʼ���Ϸ�
		break;
	case false:
		jval = 12;
	default:
		break;
	}

	cin >> getchar;
	return 0;
}