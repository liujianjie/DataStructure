#include <iostream>

using namespace std;

class example
{
public:
    example(int n)
    {
        i = n;
        cout << "Constructing\n ";
    }
    ~example()
    {
        cout << "Destructing\n";
    }
    int get_i()
    {
        return i;
    }
private:
    int i;
};
int sqr_it(example o)
{
    return () * ();
}

int main() {
    example x(10);
    cout << () << endl;
    cout << sqr_it(x) << endl;


	return 0;
}