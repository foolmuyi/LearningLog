#include <iostream>

using namespace std;


typedef unsigned char vec3b[3];

int main()
{
    unsigned char color1[3] = {77, 88, 99};
    vec3b color2 = {77, 88, 99};

    cout << color1 << endl;
    cout << color2 << endl;

    return 0;
}