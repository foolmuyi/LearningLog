#include <iostream>

using namespace std;


int main()
{
    int n = 5;
    int sum;

    while (n > 0)  // always true
    {
        sum += n;
        cout << "n = " << n << endl;
        cout << "sum = " << sum << endl;
    }
    return 0;
}