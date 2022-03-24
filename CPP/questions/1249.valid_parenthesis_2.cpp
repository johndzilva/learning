#include <iostream>
#include <stack>
#include <string>
using namespace std;

string solution(string s)
{
    stack<int> st;
    string res = "";

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            if (st.empty())
                s[i] = '#';
            else
                st.pop();
        }
    }

    while (!st.empty())
    {
        s[st.top()] = '#';
        st.pop();
    }

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != '#')
            res.push_back(s[i]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = ")))(((";
    cout << solution(s);
    return 0;
}
