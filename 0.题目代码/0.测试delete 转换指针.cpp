#include <iostream>
using namespace std;
class ScriptableEntity {
public:
	virtual ~ScriptableEntity() { cout << "~ScriptableEntity()" << endl; }
};
class CameraController : public ScriptableEntity {
public:
	virtual ~CameraController() { cout << "~CameraController()" << endl; }
};
void main() {
	// �������ջ�ϵģ���*s = &s1;��delete s; s1���ڴ�ᱻ��������ǳ���main������s1�ֻᱻ����һ�飬���Իᱨ��
	//ScriptableEntity s1;
	//ScriptableEntity* s = &s1;

	ScriptableEntity* sp1 = new ScriptableEntity;
	// ������ɾ����ʽ��ֻ�����~ScriptableEntity()
	delete sp1;
	//delete (ScriptableEntity*)sp1;

	ScriptableEntity* sp2 = new CameraController;
	// ������ɾ����ʽ������� ~CameraController() Ȼ�� ~ScriptableEntity()����������������ð�
	//delete sp2;
	delete (ScriptableEntity*)sp2;
}
