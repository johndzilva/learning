// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true

// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool validSubPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

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
    int deletion = 1;
    while (start < end)
    {
        if (newStr[start] != newStr[end])
        {
            return validSubPalindrome(s, start + 1, end) || validSubPalindrome(s, start, end - 1);
        }
        start++;
        end--;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    cout << palindrome_check("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    // cout << palindrome_check("abca");
    // cout << palindrome_check("race car");
    return 0;
}
