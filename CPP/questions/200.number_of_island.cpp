// 200. Number of Islands
// Medium

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's
// (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally
// or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

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

int numIslands(vector<vector<char>> &grid)
{
    if (grid.size() == 0)
        return 0;

    int count = 0;
    queue<vector<int>> q;

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (grid[row][col] == '1')
            {
                count++;
                q.push({row, col});
                while (q.size())
                {
                    vector<int> currPos = q.front();
                    q.pop();
                    int currRow = currPos[0];
                    int currCol = currPos[1];
                    grid[currRow][currCol] = '0';

                    for (auto i : direction)
                    {
                        vector<int> currDir = i;
                        int nextRow = currRow + currDir[0];
                        int nextCol = currCol + currDir[1];

                        if (nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size())
                            continue;
                        if (grid[nextRow][nextCol] == '1')
                            q.push({nextRow, nextCol});
                    }
                }
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid);
    return 0;
}
