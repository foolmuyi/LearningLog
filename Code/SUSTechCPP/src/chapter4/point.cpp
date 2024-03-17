#include <iostream>

using namespace std;


enum datatype {TYPE_INT8=1, TYPE_INT16=2, TYPE_INT32=4, TYPE_INT64=8};

struct Point{
    enum datatype type;
    union {
        int8_t data_8[3];
        int16_t data_16[3];
        int32_t data_32[3];
        int64_t data_64[3];
    };
};

size_t datawidth (struct Point pt)
{
    return size_t(pt.type)*3;
}

int64_t l1norm(struct Point pt)
{
    int64_t result = 0;
    switch(pt.type)
    {
        case TYPE_INT8:
            result = abs(pt.data_8[0]) + abs(pt.data_8[1]) + abs(pt.data_8[2]);
            break;
        case TYPE_INT16:
            result = abs(pt.data_16[0]) + abs(pt.data_16[1]) + abs(pt.data_16[2]);
            break;
        case TYPE_INT32:
            result = abs(pt.data_32[0]) + abs(pt.data_32[1]) + abs(pt.data_32[2]);
            break;
        case TYPE_INT64:
            result = abs(pt.data_64[0]) + abs(pt.data_64[1]) + abs(pt.data_64[2]);
            break;
    }
    return result;
}


int main()
{
    Point pt1 = {TYPE_INT8, .data_8={-1, 2, 4}};
    Point pt2 = {TYPE_INT64, .data_64={-4, 6, -8}};

    cout << "Data width = " << datawidth(pt1) << endl;
    cout << "Data width = " << datawidth(pt2) << endl;
    cout << "L1 norm = " << l1norm(pt1) << endl;
    cout << "L1 norm = " << l1norm(pt2) << endl;

    return 0;
}