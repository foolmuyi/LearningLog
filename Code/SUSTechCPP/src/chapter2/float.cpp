#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float f1 = 1.2f;
    float f2 = f1 * 1000000000000000;

    cout << "f1: " << fixed << setprecision(15) << f1 << endl;
    cout << "f2: " << fixed << setprecision(15) << f2 << endl;

    float f3 = 2.3E+9f;
    float f4 = f3 + 10;
    cout << "f3: " << fixed << _S_floatfield << f3 << endl;
    cout << "f4: " << fixed << _S_floatfield << f4 << endl;
    cout << "f3-f4= : " << (f3 - f4) << endl;
    cout << -1.0/0.0f << endl;
    cout << 0.0f/0.0f << endl;

    return 0;
}