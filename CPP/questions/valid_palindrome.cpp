// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool palindrome_check(string s)
{
    if (s.length() <= 1)
        return true;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string newStr = "";
    for (auto c : s)
    {
        if (c != ' ' && (isalpha(c) || isdigit(c)))
            newStr.push_back(c);
    }
    int start = 0;
    int end = newStr.length() - 1;
    while (start < end)
    {
        if (newStr[start] == newStr[end])
        {
            start++;
            end--;
        }
        else
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    cout << palindrome_check("0P");
    cout << palindrome_check("race car");
    return 0;
}
