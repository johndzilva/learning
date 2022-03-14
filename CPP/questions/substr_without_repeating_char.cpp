// Given a string s, find the length of the longest substring without repeating characters.
// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int substring(string s)
{
    if (s.length() <= 0)
        return 0;
    int max = 0;
    for (size_t left = 0; left < s.length() - 1; left++)
    {
        unordered_map<char, bool> known;
        int currentLenth = 0;
        for (size_t right = left; right < s.length() - 1; right++)
        {
            if (known.find(s[right]) == known.end())
            {
                currentLenth++;
                known[s[right]] = true;
                max = currentLenth > max ? currentLenth : max;
            }
        }
    }
    return max;
}

int optimal_solution(string s)
{
    if (s.length() <= 1)
        return s.length();
    int left = 0, count = 0;
    unordered_map<char, int> seenList;
    for (auto right = 0; right < s.length(); right++)
    {
        char currentChar = s[right];
        if (seenList.find(currentChar) != seenList.end())
        {
            left = max(seenList[currentChar], left);
        }
        count = max(count, right - left + 1);
        // put in hash map
        seenList[currentChar] = right + 1;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    cout << optimal_solution("au");
    return 0;
}
