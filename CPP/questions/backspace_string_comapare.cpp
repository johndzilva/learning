// Given two strings s and t, return true if they are equal when both are typed
// into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

#include <iostream>
#include <string>

using namespace std;

bool backspace_string_compare(string s, string t)
{
    string ss, tt = "";
    for (auto i : s)
    {
        if (i == '#' && !ss.empty())
            ss.pop_back();
        else if (i != '#')
            ss.push_back(i);
    }
    for (auto i : t)
    {
        if (i == '#' && !tt.empty())
            tt.pop_back();
        else if (i != '#')
            tt.push_back(i);
    }
    if (ss.compare(tt) == 0)
        return 1;
    else
        return 0;
}

bool optimal_solution(string s, string t)
{
    int sback = 0, tback = 0;
    int p1 = s.length() - 1;
    int p2 = t.length() - 1;

    while (p1 >= 0 || p2 >= 0)
    {
        while (p1 >= 0)
        {
            if (s[p1] == '#')
            {
                sback++;
                p1--;
            }
            else if (sback > 0)
            {
                sback--;
                p1--;
            }
            else
                break;
        }
        while (p2 >= 0)
        {
            if (t[p2] == '#')
            {
                tback++;
                p2--;
            }
            else if (tback > 0)
            {
                tback--;
                p2--;
            }
            else
                break;
        }
        if (p1 >= 0 && p2 >= 0 && s[p1] != t[p2])
            return false;
        if (p1 > 0 != p2 > 0)
            return false;
        p1--;
        p2--;
    }
    return true;
}

int main(int argc, char const *argv[])
{

    string s = "y#fo##f";
    string t = "y#f#o##f";
    string s1 = "ab#c";
    string t1 = "ad#c";
    // cout << backspace_string_compare(s, t);
    cout << optimal_solution(s1, t1);
    return 0;
}
