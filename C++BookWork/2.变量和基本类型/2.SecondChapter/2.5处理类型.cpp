#include <iostream>

using namespace std;
int main() 
{
	int getchar;

	// 2.5.1 ���ͱ���
	typedef double wages;
	typedef wages base, *wagesp;//wagesp ��double*��ͬ���

	using Wages = double;
	wages hourly, weekly;

	// �� ָ�롢���������ͱ���
	int ccs = 0, uu = 0;
	//int const *testps = &ccs;// ����ָ�����Ϊ������ָ��
	const int* testps = &ccs;// ���ǳ���ָ�� 
	testps = &uu;
	//*testps = 10;

	typedef char *pstring;
	// ����˵ pstring��ָ���ַ���ָ�룬const�����η������Ծ�Ϊ����ָ�롣��
	const pstring cstr = 0;//cstr��ָ��char�ĳ���ָ�룿�� pstring �� char*��ͬ��� �벻���� ��֪����ô���
	const pstring *otherpoints; // otherpoints��ָ��,���Ķ�����ָ��char�ĳ���ָ�룬��ָ���ָ��
								//cstr = &c;//�ð�
	char *const pointconst = 0;
	const char *const pointconst2 = 0;
	otherpoints = &cstr;
	otherpoints = &pointconst;
	//otherpoints = &pointconst2;//���� ��Ϊotherpointsû������ײ�const

	char cchar = 'd';
	//cstr = &cchar; ���� ��Ϊ����ָ��

	// test ��λ��
	pstring const  cstr2 = 0;//cstr��ָ��char�ĳ���ָ�룿�� pstring �� char*��ͬ��� �벻���� ��֪����ô���
	pstring const  *otherpoints2; // otherpoints��ָ��,���Ķ�����ָ��char�ĳ���ָ�룬��ָ���ָ��
								//cstr = &c;//�ð�

	// ���ǳ���ָ�롣��
	//cstr2 = &cchar;
	otherpoints = &cstr2;
	otherpoints2 = &cstr;
	otherpoints2 = &pointconst;

	// 2.5.2auto����˵����
	int item1 = 10;
	float item2 = 30.0;
	auto item = item1 + item2;
	cout << item << endl;

	// (2)
	auto autois = 0, *autop = &autois;
	//auto autosz = 0, autopi = 3.14;//��һ��int һ�� float

	// ������������
	int autoj = 0, &autor = autoj;
	auto autoa = autor;//Ϊautor���õĶ���Ϊ����

	

	// (2)����Զ���const ���ײ�const�ᱣ������
	 int autoi = 0;
	const int ci = autoi, &cr = ci;
	auto b = ci; // ���Զ��� b��һ������
	auto c = cr; // ���� c������
	auto d = &autoi;// d ��һ������ָ��
	auto e = &ci; // e��һ��ָ������������ָ�� û�������ײ�const

	// ��3��������ƶϳ���constΪ����const ��ȷָ������
	const auto f = ci;

	// (4)�ɽ����õ�������Ϊauto ��ԭ���ĳ�ʼ��������ͬ ����
	auto &g = ci;
	//auto &h = 42;//error ��Ϊ����const ����
	const auto &j = 42;//true

	//(6) һ��������ͱ���һ�£�& *ֻ������ĳ��������
	auto k = ci, &l = autoi;// ����  ��������
	auto &m = ci, *p = &ci;// �������� ָ�����ͳ�����ָ��
	//auto &n = autoi,  *p2 = &ci;//error i��int &ci��const int

	// 2.5.3 decltype����ָʾ��
	const int deci = 0, &decj = deci;
	decltype(deci) decx = 0; // decx��typeΪconst int
	decltype(decj) decy = decx;// decy ��constint& 
	decltype(decj) z = 48;		//error:z��һ�����ã������ʼ��

	// ����decltype �� ����
	// �����ñ��ʽ ���ر��ʽ
	int twodeci = 42, *twodecp = &twodeci, &twodecr = twodeci;
	decltype(twodeci + 0) twodecb;
	decltype(*twodecp) twodecc = twodeci;// error twodecc��int& ������ָ��
	const decltype(*twodecp) twodecc2 = twodeci;// ǰ׺const���ӵ�����

	const int& test3 = 54;

	// (2)decltype ����ʽ�������
	decltype((twodeci)) twodecd = twodeci; // error,twodecd��int& �����ʼ��
	decltype(twodeci) twodece;//int

	twodecc = 45;
	twodecc2 = 60;
	twodecd = 90;

	cout << twodeci << endl;
	cin >> getchar;
	return 0;
}