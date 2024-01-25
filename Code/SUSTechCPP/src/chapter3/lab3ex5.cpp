#include <iostream>

using namespace std;


int main()
{
    int n, fa;  // not initialized

    do
    {
        fa *= n;
        n++;
    } while (n <= 10);

    cout << "fa = " << fa << endl;

    return 0;
    
}