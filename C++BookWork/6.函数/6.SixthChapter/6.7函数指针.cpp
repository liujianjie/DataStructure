#include <iostream>

using namespace std;

bool lengthCompare(const string &s1, const string &s2) {
	if (s1.size() < s2.size()) {
		return false;
	}
	else {
		return true;
	}
}
void ff(int *){}
void ff(unsigned int){}


// �������ܶ��庯�����͵��βΣ������βο�����ָ������ָ�룬�������Ǻ������ͣ���ʵ��ָ��
void useBigger(const string &s1, const string &s2, bool pf(const string&, const string&)){}
//�ȼ۵�����
void useBigger(const string &s1, const string &s2, bool(*pf)(const string&, const string&));
//string ss1 = "sdf", ss2 = "aasdf";
//void useBigger(const string &s1, const string &s2, lengthCompare(ss1,ss2) {}// ���ɡ�

// ʹ�����ͱ���
// Func ��func2�Ǻ�������
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2;

// Funcp ��funcp2�Ǻ���ָ�� ����Ϊdecltype���غ������ͣ�����func2��funcp2�������Զ�ת����ָ������
typedef bool (*Funcp)(const string&, const string&);
typedef decltype(lengthCompare) *Funcp2;
void useBigger(const string &s1, const string &s2, Func);//���������Զ�ת����ָ��
void useBigger(const string &s1, const string &s2, Funcp2);



int main() {
	int g;
	bool(*pf)(const string &s1, const string &s2);// δ��ʼ��? ֻ���������ָ��ָ������ָ�룬������const string ���ã�����ֵ��bool����
	// ���Ų����٣���ȻΪpf�ĺ������ú�������bool*
	// ����ʹ�ú���ָ�� ��ֵ��
	pf = lengthCompare;//pfָ�� �Ǹ�������lengthCompare��Ϊһ��ֵʹ��ʱ���Զ���ת����ָ��
	pf = &lengthCompare;// �ȼ�

	// ����ֱ��ʹ��ָ������ָ����øú�����������ǰ������ָ�� ʹ�ã�
	bool b1 = pf("hello", "goodbye");// ���� lengthCompare����
	cout << b1 << endl;
	bool b2 = (*pf)("hello", "goodbye");// һ���ȼ۵ĵ���
	cout << b2 << endl;
	bool b3 = lengthCompare("sdfsdf", "sa");//��һ���ȼ۵ĵ���
	cout << b3 << endl;
	// ��ָ��ͬ�������͵�ָ��䲻����ת��������˼����pfָ�붨��ĺ������� ������ָ�������ĺ�������
	// ��ʹ����ֵ��byte����ת����int Ҳ���� �����Ĳ����á�
	// ����Ϊnullptr ��  0
	string::size_type sumlength(const string&, const string&);
	bool cstringCompare(const char*, const char*);
	pf = 0;
	//pf = sumlength; // �������Ͳ�ƥ��
	//pf = cstringCompare;// �²����Ͳ�ƥ��
	pf = lengthCompare;

	int(*pf2)(const int &a1, const int &a2);
	short test1(const int&a1, const int &a2);
	//pf2 = test1;

	// 3.���غ�����ָ�� ҲҪָ��������һ�����������β��뷵��ֵ���ö�Ӧ


	//void(*pf3)(int) = ff;//error
	//double(*pf4)(int *) = ff;//error
	void(*pf4)(int *) = ff;//true

	// ��������ָ���β�


	// Ҳ����ֱ�ӰѺ�����Ϊʵ��ʹ�ã���ʱ�����Զ�ת����ָ�룺���ܵ����β�
	string s1 = "j",s2 = " d";
	useBigger(s1, s2, lengthCompare);

	// �ġ�����ָ������ָ��
	// �뺯���ββ�һ������Ҫָ��ָ����ʽ�������Ǻ�������
	// ��using����һ�����غ���ָ��ĺ���
	using F = int(int*, int);	// F�Ǻ������ͣ���������
	using PF = int(*)(int *, int);// PF��ָ������
	PF f1(int);
	//F  f12(int); // error:F�Ǻ������ͣ�f1���ܷ���һ������
	F  *f1(int);

	// Ҳ�����������ʽֱ������f1;
	int(*f1(int))(int *, int);// ���������˳���Ķ���f1���β��б�����f1�Ǹ�������f1ǰ����* ����f1����һ��ָ�룬ָ�������Ҳ�����β��б�����ָ��ָ�������ú����ķ���������int

	// β�÷������͵ķ�ʽ
	auto fi(int) -> int(*)(int*, int);

	// ��auto��decltype���ں���ָ������
	// ���֪��Ҫ�����ĸ�������
	string::size_type sumlength2(const string&, const string&);
	string::size_type largerlength(const string&, const string&);

	// ע�� decltypeֻ�Ǻ������ͣ����Ǻ���ָ��
	decltype(sumlength2) *getfcns(const string&);

	cin >> g;
	return 0;
}