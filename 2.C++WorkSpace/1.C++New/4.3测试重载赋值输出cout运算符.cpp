#include <iostream>
using namespace std;

class Complex {
public:
	Complex(){}
	Complex(int r, double i):real(r),img(i){
		cout << "���εĹ��캯��" << endl;
	}
	Complex(const Complex& com) {
		cout << "���ƹ���" << endl;
		this->real = com.real;
		this->img = com.img;
	}
	Complex& operator=(const Complex& com) {
		cout << "��ֵ�����" << endl;
		// ���µĸ�ֵ�������Ǵ���ģ���Ϊ�������������ʱ����������
		//Complex coms;
		//coms = com; // ��ֵ������ظ�����
		//Complex coms(com); // ���ø��ƹ��캯����û��д���ǲ��������ݵ�
		//Complex coms(com.real, com.img);
		//Complex coms;
		//coms.img = co.img;
		//coms.real = co.real;
		//return coms;
		Complex coms(com.real, com.img);
		return coms;
		// ��Ҫ����this��ָ�����
		//this->real = com.real;
		//this->img = com.img;
		//return *this;
	}
	Complex& operator+(const Complex &com) {
		cout << "+�����" << endl;
		Complex coms(this->real + com.real, this->img + com.img);
		return coms;
	}
	~Complex() {
		//cout << "����" << endl;
	}
public:
	int real;
	double img;
};
ostream& operator<<(ostream& os,const Complex& b) {
	os << b.real << " " << b.img;
	return os;
}
int main()
{
	// ���Ը�ֵ�����أ�ʲôʱ������
	Complex cp1(12, 2.4), cp3(11, 3.4),cp2;
	cp2 = cp1; // ��������ʱ�����ȵ����긳ֵ�����������
	Complex cp4 = cp1 + cp3; // ���ƹ���ǰ��������
	cout << cp4 << endl;
	getchar();

	//Complex c1(12, 2.3);
	//Complex c3(12, 2.3);
	//Complex c2;
	//c2 = c1;
	//cout << c2.real << endl;
	//cout << c1 << endl;;
	//cout << c2 << endl;
	//Complex c4 = c1 + c3;
	//c4 = c1 + c3; ���ø�ֵ
	//cout << c4;

	return 0;
}

