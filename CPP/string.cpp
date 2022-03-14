#include <iostream>
#include <string>

using namespace std;

void string_functions()
{
    string string_A = "loremIpsum!!";

    cout << "length() = " << string_A.length() << endl;
    cout << "capacity() = " << string_A.capacity() << endl;

    string_A.resize(20);

    cout << "length() = " << string_A.length() << endl;
    cout << "capacity() = " << string_A.capacity() << endl;

    string_A.shrink_to_fit();
    cout << "length() = " << string_A.length() << endl;
    cout << "capacity() = " << string_A.capacity() << endl;

    for (size_t i = 0; i < string_A.size(); i++)
    {
        cout << string_A[i];
    }

    // or using iterator

    string::iterator itr;
    for (itr = string_A.begin(); itr < string_A.end(); itr++)
    {
        cout << *itr;
    }
}
int main(int argc, char const *argv[])
{
    string_functions();
    return 0;
}