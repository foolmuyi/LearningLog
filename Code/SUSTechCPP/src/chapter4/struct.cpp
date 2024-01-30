#include <iostream>
#include <cstring>

using namespace std;


struct Student{
    char name[4];
    int born;
    bool male;
};

struct Student1{
    char name[5];
    int born;
    bool male;
};

struct Student2{
    int born;
    char name[5];
    bool male;
};

int main()
{
    struct Student stu;
    strcpy(stu.name, "Yu");
    stu.born = 2000;
    stu.male = true;

    cout << "Name: " << stu.name << endl;
    cout << "Born: " << stu.born << endl;
    cout << "Gender: " << (stu.male ? "Male" : "Female") << endl;

    Student students[100];
    cout << sizeof(students) << endl;

    Student1 stu1;
    Student2 stu2;

    cout << sizeof(stu1) << endl;
    cout << sizeof(stu2) << endl;

    return 0;
    
}