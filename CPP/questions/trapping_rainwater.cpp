// Given n non-negative integers representing an elevation map
// where the width of each bar is 1, compute how much water it can trap after raining.

// Difficulty: Hard

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int> &height)
{
    int result = 0;
    int maxLeft = 0, maxRight = 0;
    int leftPtr = 0;
    int rightPtr = height.size() - 1;
    while (leftPtr < rightPtr)
    {
        // check which one we need to operate
        if (height[leftPtr] <= height[rightPtr])
        {
            if (maxLeft <= height[leftPtr])
                maxLeft = height[leftPtr];
            else
                result += maxLeft - height[leftPtr];
            leftPtr++;
        }
        else
        {
            if (maxRight <= height[rightPtr])
                maxRight = height[rightPtr];
            else
                result += maxRight - height[rightPtr];
            rightPtr--;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> h = {0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2};
    int result = trap(h);
    cout << result;
    return 0;
}
