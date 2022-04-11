#include <iostream>
#include <string>

using namespace std;

void string_functions()
{
    string string_A = "loremIpsum!!";
    string string_B = "new_string";

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

    // inserting a character at the end of the string
    string_A.push_back('!');

    // deleting a character from the end of the string
    string_A.pop_back();

    // swapping two strings
    string_A.swap(string_B);

    // inserting a character at the beginning of the string
    string_A.insert(0, "new_");
}
int main(int argc, char const *argv[])
{
    string_functions();
    return 0;
}