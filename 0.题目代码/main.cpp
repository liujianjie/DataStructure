#include <iostream>
using namespace std;

class Input {
public:
	static void GetMouseX();
};
#if LinuxInput
using namespace std;
void Input::GetMouseX() {
	cout << "Windows GetMouseX" << endl;
}
#endif
#define WindowsInput 1
#if WindowsInput
using namespace std;
void Input::GetMouseX() {
	cout << "Windows GetMouseX" << endl;
}
#endif
void main() {
	Input::GetMouseX();
}