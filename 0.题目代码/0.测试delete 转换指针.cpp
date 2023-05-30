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
	// 这个是在栈上的，若*s = &s1;当delete s; s1的内存会被清除，但是出了main作用域，s1又会被清理一遍，所以会报错。
	//ScriptableEntity s1;
	//ScriptableEntity* s = &s1;

	ScriptableEntity* sp1 = new ScriptableEntity;
	// 这两种删除方式都只会调用~ScriptableEntity()
	delete sp1;
	//delete (ScriptableEntity*)sp1;

	ScriptableEntity* sp2 = new CameraController;
	// 这两种删除方式都会调用 ~CameraController() 然后 ~ScriptableEntity()，更多的是提醒作用吧
	//delete sp2;
	delete (ScriptableEntity*)sp2;
}
