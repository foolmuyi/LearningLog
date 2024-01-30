#include <iostream>

using namespace std;


union ipv4addr{
    uint32_t addr32;
    uint8_t addr8[4];
};

int main()
{
    ipv4addr addr;
    cout << sizeof(addr) << endl;

    return 0;
}