#include <iostream>

using namespace  std;


int main()
{
    int len = -2;
    while (len < 10)
    {
        int num_array[len];
        cout << "len = " << len << "\t";
        cout << "sizeof(num_array) = " << sizeof(num_array) << endl;
        len++;
    }
}