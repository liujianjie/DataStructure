#include <iostream>
#include <vector>

using namespace std;


void Print(vector<int> vec) {
	vector<int>::iterator begin = vec.begin();
	vector<int>::iterator end = vec.end();
	for (; begin != end; begin++) {
		cout << *begin << endl;
	}
}
void main() {
	vector<int> vec;
	vector<int>::iterator m_LayerInsert = vec.begin();
	vector<int>::iterator begin = vec.begin();
	vector<int>::iterator end = vec.end();
	
	m_LayerInsert = vec.emplace(m_LayerInsert, 3);
	cout << *m_LayerInsert << endl;
	m_LayerInsert = vec.emplace(m_LayerInsert, 4);
	cout << *m_LayerInsert << endl;
	Print(vec);
}