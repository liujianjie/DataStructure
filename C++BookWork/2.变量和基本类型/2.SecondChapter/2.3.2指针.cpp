#include <iostream>

using namespace std;
int main()
{

	int getchar;
	
	// 2.3.2ָ��
	int *ip1, *ip2, ip3;// ���� δ���壬Ϊ��ȷ��ֵ ��ò�Ҫʹ��
	int ival = 42; 
	int *ps = &ival;

	double dval;
	double *pd = &dval;
	//int *pi = pd; error

	//4
	int ivals = 42,ivals2 = 45;
	int *p = &ivals;
	cout << *p << endl;// �õ�ָ��p��ָ�Ķ���
	cout << p << endl;
	
	p = &ivals2;
	*p = 32;
	cout << *p << endl;

	int &r2 = *p;
	r2 = 56;
	cout << ivals2 << endl;

	// ��.��ָ��
	int zero = 0;
	int *pi = nullptr;
	int *pi2 = 0;
	int *pi3 = NULL;

	//  ������ֵΪ0 Ҳ������ֱ�Ӹ�ֵָ���������
	int *pi4;
	pi4 = &zero;

	// �ģ�����ָ�����
	int ivalss = 1024;
	int *ipis = 0;
	int *ipis2 = &ivalss;
	if (ipis)
		cout << "true" << endl;
	if (ipis2)
		cout << "true" << endl;

	if (pi == pi2)
		cout << "pi == pi2true" << endl;
	if (pi != pi2)
		cout << "pi != pi2true" << endl;

	// �壺void* ָ��
	double obj = 3.14, *fivepd = &obj;
	void *fivepv = &obj;
	void *fivepv2 = pd;

	//cout << *fivepv << endl;
	//cout << *fivepv2 << endl;
	cout << fivepv << endl;
	cout << fivepv2 << endl;

	// ����ָ��ָ���ָ��
	int sixval = 1024;
	int *sixpi = &sixval;
	int **sixppi = &sixpi;

	printf("\n");
	cout << sixpi << endl; //ԭʼ����ĵ�ַ
	cout << *sixppi << endl; // *sixppi �õ�sixpi������Ϊ sixpi Ϊԭʼ�����ַ
	cout << sixppi << endl; // �õ��洢��sixppi�е�sixpi�ĵ�ַ
	cout << **sixppi << endl;//ԭʼ����ֵ
	
	// �ߣ�ָ��ָ�������
	int seveni = 42;
	int *sevenp;
	int *&sevenr = sevenp;
	sevenr = &seveni; // *sevenp = &seveni;
	*sevenr = 10; // *sevenp = 10;
	cout << seveni << endl;

	cin >> getchar;
	return 0;
}