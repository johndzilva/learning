#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> direction{
    {-1, 0}, // up
    {0, 1},  // right
    {1, 0},  // down
    {0, -1}, // left
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> data{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    // vector<vector<int>> data{
    //     {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<vector<bool>> seen(data.size(), vector<bool>(data[0].size(), false));
    vector<int> result;

    queue<vector<int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        vector<int> currentPos = q.front();
        q.pop();
        int row = currentPos[0];
        int col = currentPos[1];

        if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size() || seen[row][col] == true)
            continue;

        result.push_back(data[row][col]);
        seen[row][col] = true;

        for (auto i : direction)
        {
            vector<int> currDir = i;
            q.push({row + currDir[0], col + currDir[1]});
        }
    }

    for (auto a : result)
    {
        cout << a << " ";
    }

    return 0;
}
