#include <iostream>

using namespace std;


int main()
{
    char c1 = 'C';
    char c2 = 80;
    char c3 = 0x50;
    char16_t c4 = u'码';
    char32_t c5 = U'码';

    cout << c1 << ":" << c2 << ":" << c3 << endl;
    cout << +c1 << ":" << +c2 << ":" << +c3 << endl;
    cout << c4 << ":" << c5 << endl;

    return 0;
}