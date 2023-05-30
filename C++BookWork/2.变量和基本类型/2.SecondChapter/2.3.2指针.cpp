#include <iostream>

using namespace std;
int main()
{

	int getchar;
	
	// 2.3.2指针
	int *ip1, *ip2, ip3;// 声明 未定义，为不确定值 最好不要使用
	int ival = 42; 
	int *ps = &ival;

	double dval;
	double *pd = &dval;
	//int *pi = pd; error

	//4
	int ivals = 42,ivals2 = 45;
	int *p = &ivals;
	cout << *p << endl;// 得到指针p所指的对象
	cout << p << endl;
	
	p = &ivals2;
	*p = 32;
	cout << *p << endl;

	int &r2 = *p;
	r2 = 56;
	cout << ivals2 << endl;

	// 二.空指针
	int zero = 0;
	int *pi = nullptr;
	int *pi2 = 0;
	int *pi3 = NULL;

	//  当对象值为0 也不可以直接赋值指向这个对象
	int *pi4;
	pi4 = &zero;

	// 四：其它指针操作
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

	// 五：void* 指针
	double obj = 3.14, *fivepd = &obj;
	void *fivepv = &obj;
	void *fivepv2 = pd;

	//cout << *fivepv << endl;
	//cout << *fivepv2 << endl;
	cout << fivepv << endl;
	cout << fivepv2 << endl;

	// 六。指向指针的指针
	int sixval = 1024;
	int *sixpi = &sixval;
	int **sixppi = &sixpi;

	printf("\n");
	cout << sixpi << endl; //原始对象的地址
	cout << *sixppi << endl; // *sixppi 得到sixpi，就是为 sixpi 为原始对象地址
	cout << sixppi << endl; // 得到存储在sixppi中的sixpi的地址
	cout << **sixppi << endl;//原始对象值
	
	// 七：指向指针的引用
	int seveni = 42;
	int *sevenp;
	int *&sevenr = sevenp;
	sevenr = &seveni; // *sevenp = &seveni;
	*sevenr = 10; // *sevenp = 10;
	cout << seveni << endl;

	cin >> getchar;
	return 0;
}