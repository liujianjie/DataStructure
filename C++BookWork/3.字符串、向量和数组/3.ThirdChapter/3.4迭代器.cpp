#include <iostream>
#include <string>
#include <vector>

using  std::cin;
using  std::cout;
using  std::endl;
using std::vector;
using std::string;
int main() 
{
	int getchar;


	// 3.4.1 ʹ�õ�����
	vector<string> onev1 = {"1","2","3","4","5","6","7"};
	auto oneb = onev1.begin(), onee = onev1.end();// b��ʾv�ĵ�һ��Ԫ�أ�onee��ʾonev1��βԪ�صĺ�һλ����vectorΪ�գ��������

	// �������������
	vector<string> onetowv1{"d","d","f","g","g"};
	if (onetowv1.begin() != onetowv1.end())
	{
		
		auto b = onetowv1.begin();
		*b = "D";
		//cout << *b << endl;
	}
	string onetwostr{ "some nedd help" };
	if (onetwostr.begin() != onetwostr.end())
	{
		//auto currp = onetwostr.begin();
		//(*currp) = toupper(*currp);
	}

	
	for (auto onetowbegin = onetowv1.begin(); onetowbegin != onetowv1.end();onetowbegin++)
	{
		//auto currp = ;
		cout << *onetowbegin + "/";
	}
	cout << endl;

	cout << "/" << endl;
	for (auto onetowbegins = onetwostr.begin(); onetowbegins != onetwostr.end(); onetowbegins++)
	{
		cout << *onetowbegins + "/";
	}
	cout << endl;

	// ������������һ��Ԫ���Ƶ�����һ��Ԫ��
	string onethreestr("i need girl");

	for (auto onethreebegin = onethreestr.begin(); 
		onethreebegin != onethreestr.end() && !isspace(*onethreebegin); onethreebegin++)
	{
		*onethreebegin = toupper(*onethreebegin); // �ĳɴ�д��
	}
	for (auto onethreebegin = onethreestr.begin();
		onethreebegin != onethreestr.end(); onethreebegin++)
	{
		cout << *onethreebegin ;
	}
	cout << endl;

	//����������
	vector<int>::iterator onefourv1;//�ܶ�д
	vector<string>::iterator onefourv2;//�ܶ�д
	vector<int>::const_iterator oneforv3;//ֻ�ܶ�����д
	vector<string>::const_iterator onefourv4;//ֻ�ܶ�����д

	//begin��end�����
	vector<int> onefivev1;
	const vector<int> onefivev2;
	auto onefiveb = onefivev1.begin();// �õ�vector<int>::iterator
	auto onefivee = onefivev2.begin();//�õ�vector<int>::const_iterator
	auto onefive3 = onefivev2.cbegin();//�õ�vector<int>::const_iterator

	// ��Ͻ����úͳ�Ա���ʲ���
	vector<string> osixv1{"ni","ggh","sdfsd sdf","","gghsdf"};//������Ϊ��Ԫ��
	for (auto b = osixv1.cbegin();
		b != osixv1.cend() && !b->empty(); b++)
	{
		cout << *b;
	}
	cout << endl;

	// 3.4.2 ����������
	vector<int> twov1(10);
	auto twob1 = twov1.begin();
	auto twob2 = twov1.end();
	if (twob1 < twob2)
		cout << true << endl;
	else
		cout << false << endl;

	vector<int> twov2{1,2,3,4,5,6,7,8,9};
	auto twob3 = twov2.begin();
	auto twoe2 = twov2.end();
	auto mid = twob3 + (twov2.size() / 2);
	int soughtzhi = 6;
	int count = 0;
	while (mid != twoe2) 
	{
		int zhi = *mid;
		if (zhi < soughtzhi) 
		{
			twob3 = mid;// ����1 ����һ��ѭ�������������ŵ��
		}
		else if(zhi > soughtzhi){
			twoe2 = mid;
		}
		else if (zhi == soughtzhi) {
			break;
		}
		mid = twob3 + (twoe2 - twob3)/2;
			count++;
	}
	cout << "ѭ����" << count << "��"<< endl;
	cout << 1 / 2 << endl;
	cout << 5 / 2 << endl;

	cin >> getchar;
	return 0;
}