#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;// ��ҲҪ������
int main()
{
	int getchar;

	// 3.2.1��ʼ���Ͷ���string����
	string firsts1;
	string firsts2(firsts1);
	string firsts3 = firsts2;
	string firsts4("values");//firsts4������ֵvalue�ĸ��� ��������ֵ�����Ǹ����ַ���
	string firsts5 = "values";
	string firsts6(10,'c');

	// ֱ�ӳ�ʼ�� �� ������ʼ�� =�ǿ�����ʼ�� ���� ��ֱ�ӳ�ʼ����ͬʱ���ڻ��ǿ�����ʼ��

	// 3.2.2string�Ĳ���
	string twos1,twos2;
	//cin >> twos1; // �����ո񲻻����
	//cout << twos1 ;
	//cin >> twos1 >> twos2;
	//cout << twos1 << twos2;

	// ��ȡδ֪������string����
	string word;
	//while (cin>>word) {
	//	cout << word << endl;
	//}

	// getline
	string line;
	//while (getline(cin,line))
	//	cout << line << endl;

	// empty size 
	bool bln;
	while (getline(cin, line))
	{
		bln = line.empty();
		if (!line.empty())
			cout << bln << endl;
		else
			cout << bln << endl;
		//if (line.size() > 10) // yujavaͬ ��������byte
		//	cout << line << endl;
	}

	// size_type
	auto se = line.size();// ���޷��ŵ���������

	// �Ƚ�string����
	string strs = "Hello";
	string strphrase = "Hello World";
	string strlang = "Hi";// �Ƚϵڶ�����ĸ ��ͬ ����ĸ����˭��˭С������ľ�û�б���

	if (strs < strphrase)
		cout << "strs < strphrase" << endl;
	if (strphrase < strlang)
		cout << "strphrase < strlang" << endl;

	// Ϊstring��ֵ
	string st1(10, 'c'), st2;
	st1 = st2;

	// ����string���
	string plusstr1 = "hello";
	string plusstr2 = "world";
	string plusstr3 = plusstr1 + plusstr2;
	plusstr1 += plusstr2;// ׷�����ݵ�plustr1��

	// ����ֵ��string�������
	string zimianstr1 = "hello";
	string zimianstr2 = "world";
	string zimianstr3 = zimianstr1 + "," + zimianstr2 + '\n';//���������и�string

	cout << zimianstr3 << endl;
	string zimianstr4 = zimianstr1 + ",";
	//string zimianstr5 = "hello" + "world";//error;
	string zimianstr6 = zimianstr1 + "," + "world";//(zimainstr + ",") + world
	//string zimianstr7 = "," + "world" + zimainstr1;//error ��������������
	// �ַ�������ֵ�����Ǳ�׼������string�Ķ���

	// test ���� �ܷ�󶨶��
	int testrefi = 10,testrefj = 20;
	int &testref = testrefi;
	//&testref = testrefj; ֻ������һ��

	// 3.2.3 ����string�����е��ַ�
	// ���������
	string threestr = "some asdf";
	for (auto a : threestr)
		cout << a << endl;//�����ǰ�ַ������ҽ������з�endl;
	string threess("Hello World!!!!");
	decltype(threess.size()) punct_cnt = 0;
	for (auto c : threess) 
	{
		if (ispunct(c))
			punct_cnt++;
	}
	cout << punct_cnt << endl;

	// �ı�string���ַ� ��Ҫ������
	string fourstr("Hello Wolrddd");
	for (auto &c : fourstr) // ÿ��c�����������´����� ��Ϊc���ܸı�ָ��Ķ���
		c = toupper(c);
	cout << fourstr << endl;

	// �ı䲿���ַ� ���±� �����
	string fivestr("some string");
	if (!fivestr.empty())
		cout << fivestr[0] << endl;
	fivestr[0] = toupper(fivestr[0]);
	cout << fivestr << endl;

	// && ��·�����
	for (decltype(fivestr.size()) index = 0; index != fivestr.size() && !isspace(fivestr[index]); index++)
		fivestr[index] = toupper(fivestr[index]);

	cout << fivestr << endl;

	// С���� ת��Ϊ16����
	const string sixteenstr = "0123456789ABCDEF";
	decltype(sixteenstr.size()) number;
	string cinstr;
	while (cin >> number)
		if (number < sixteenstr.size())
			cinstr += sixteenstr[number];

	cout << cinstr << endl;

	string getchars = "";
	cin >> getchar;
	return 0;
}