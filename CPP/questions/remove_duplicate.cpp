// Remove duplicate element from the array
// Time complexity O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> remove_duplicate(int *arr, int n)
{
    vector<int> output;
    unordered_map<int, bool> my_map;

    for (size_t i = 0; i < n; i++)
    {
        if (my_map.count(arr[i]) == 0)
        {
            output.push_back(arr[i]);
            my_map[arr[i]] = true;
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 5, 7, 2, 4, 1, 3, 6, 7, 8, 2, 5, 5, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> output = remove_duplicate(arr, n);
    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << " " << endl;
    }
    return 0;
}
