#include <iostream>
#include <string>

using namespace std;

int main()
{
	// ��ʽ���� ת��
	int ival = 3.541 + 3;
	// ��������������ˡ�Ҫ�㣺�����������޷������͵��������

	// 4.11.2 ������ʽ����ת��
	// 1.����ת��Ϊָ��
	// 2.ת��bool����
	// 3.ת��Ϊ����
	/// �����Ͷ����ת��
	string s, t = "a value";

	// 4.11.3 ��ʽת��
	// 1.static_cast ֻҪ�ײ㲻����const������ʹ�ã��ײ�const ���õĶ��� �� ָ�������const
	double slope = static_cast<double>(10 / 3);
	cout << slope << endl;

	int tests0 = slope;
	int testsl = static_cast<int>(slope);// ������������͸�С���������� ������ʾ��ʧ������Ϣ��

	// ���ڱ������޷��Զ�ִ�е�����ת������
	int fetd = 10;
	void* fetdp = &fetd;
	int *fetdpsc = static_cast<int*>(fetdp);
	cout << *fetdpsc << endl;
	double *fetdpsc2 = static_cast<double*>(fetdp);// ����ȷ��ת��������;���ָ����ָ�����ͣ���Ȼ ����δ�������Ϊ
	cout << *fetdpsc2 << endl;

	// 2.const_cast ȥ��������
	char twoneed = 'a';
	const char  *twochar1 = &twoneed;
	char twoc1 = 'A';
	// char *twocharp =  �����ô������ ����
	const char *twocharp =  const_cast<char*>(twochar1);// ��ȷ������ͨ��twocharpдֵδ������Ϊ�� ʹ����δ��ʼ���ľֲ�������twochar1������Ϊû�г�ʼֵ
	//ȥ���˳����ԣ����Խ���д����
	twochar1 = 0;
	twochar1 = &twoc1;
	cout << *twochar1 << endl;
	cout << *twocharp << endl;// twochar1 �Ĳ��˲�Ӱ��twocharp
	
	// ����дֵ����Ϊtwocharp δ��ʼ������twochar1 δ����0 ����char *twocharp = ��ֵʱ
	/*twocharp = &twoc1;
	cout << *twocharp << endl;*/

	const char *twochar2 = &twoc1;
	// error  ���ֻ�ܸı�����
	//char *twocharq2 = static_cast<char*>(twochar2);
	static_cast<string>(twochar2);
	//const_cast<string>(twochar2);// error ���ֻ�ܸı䳣������

	// 3.reinterpret_cast Ϊ��������λģʽ�ṩ�ϵͲ���ϵ����½��� Σ�յģ���Ϊ��ָ����ʵ�����Ǳ�����
	int threeint1 = 10;
	int *threeip = 0; //���׳��쳣
	//int *threeip = &threeint1;
	char *threepc = reinterpret_cast<char*>(threeip);
	//string threestr(threepc); //���ش��󡣱�������֪�� threepcʵ��ָ�����int����
	//cout << *threepc << endl;
	//string threestr(10); ֱ�Ӹ�ֵ�ǿ��Բ��Ҵ����

	// ��ʽ��ǿ������ת��
	char *jiushipc = (char*)threeip;// �൱reinterpret_cast<char*>
	//string threestr2(jiushipc); //���ش��󡣱�������֪�� threepcʵ��ָ�����int���ͣ��������û�С���
	getchar();
	return 0;
}