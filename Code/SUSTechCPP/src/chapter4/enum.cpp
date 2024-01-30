#include <iostream>

using namespace std;


enum color {WHITE, BLACK, RED, GREEN, BLUE, YELLOW, NUM_COLORS};

int main()
{
    // color pen_color = RED;
    color pen_color = color(3);
    cout << pen_color << endl;
    cout << sizeof(color) << endl;
}