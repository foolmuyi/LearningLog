#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str1 = "Hello";
    string str2 = "SUSTech";
    string result = str1 + ", " + str2;

    cout << "Result = " + result << endl;
    cout << "Result length = " << result.length() << endl;
    cout << boolalpha;
    cout << "str1 < str2 ?:  " << (str1 < str2) << endl;
    cout << str1[66] << endl;  // no bound check

    return 0;
}