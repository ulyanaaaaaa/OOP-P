#include <iostream>
using namespace std;

int main()
{
    int i;
    cin.setf(ios::skipws);
    cin >> i;
    cout << i;
    cout.setf(ios::right);
    cout.width(100);
    cout << "Hello World!" << ends;
    cout.unsetf(ios::right);
    cout << "Hello World!" << endl;
    return 0;
}
