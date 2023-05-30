#include <iostream>
#include <vector>

using namespace std;
// 一个个粒子属性
struct Particle
{
	/*glm::vec2 Position;
	glm::vec2 Velocity;
	glm::vec4 ColorBegin, ColorEnd;*/
	float Rotation = 0.0f;
	float SizeBegin, SizeEnd;

	float LifeTime = 1.0f;
	float LifeRemaining = 0.0f;

	bool Active = false;
};
void main() {
	vector<int> vec;
	vec.resize(10);
	cout << "----------" << endl;
	unsigned int ct = 10;
	cout << (0 % ct) << endl;
	cout << (-1 % ct) << endl;
	cout << (-2 % ct) << endl;
	cout << (-3 % ct) << endl;
	vector<Particle>::size_type ty = 1000;
	cout << (0 % ty) << endl;
	cout << (-1 % ty) << endl;
	cout << (-2 % ty) << endl;
	cout << (-3 % ty) << endl;

	vector<Particle> vec2;
	vec2.resize(1000);
	cout << (0 % vec2.size()) << endl;
	cout << (-1 % vec2.size()) << endl;
	cout << (-2 % vec2.size()) << endl;
	cout << (-3 % vec2.size()) << endl;
	cout << "--------" << endl;
	int m = 9;
	for (int i = 0; i < 30; i++) {
		m = --m % vec.size();
		cout << m << endl;
	}
	cout << "---------------" << endl;
	m = 9;
	unsigned int count = 10;
	for (int i = 0; i < 30; i++) {
		m = --m % count;
		cout << m << endl;
	}

	
}