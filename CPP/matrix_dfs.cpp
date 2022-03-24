#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> direction{
    {-1, 0}, // up
    {0, 1},  // right
    {1, 0},  // down
    {0, -1}, // left
};

void dfs(vector<vector<int>> data, int row, int col, vector<vector<bool>> &seen, vector<int> &result)
{
    if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size() || seen[row][col] == true)
        return;

    result.push_back(data[row][col]);
    seen[row][col] = true;

    for (auto i : direction)
    {
        vector<int> currDir = i;
        dfs(data, row + currDir[0], col + currDir[1], seen, result);
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> data{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<vector<bool>> seen(data.size(), vector<bool>(data[0].size(), false));
    vector<int> result;

    dfs(data, 0, 0, seen, result);

    for (auto a : result)
    {
        cout << a << " ";
    }

    return 0;
}
