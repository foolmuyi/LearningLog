#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    double a, b, c;
    a = 0.1;
    b = 0.2;
    c = 0.3;

    // printf("%.2f\n%.2f\n%.2f\n", a, b, c);
    cout << fixed << setprecision(2) << a 
    << endl << b << endl << c <<endl;
}