// 994. Rotting Oranges
// Medium

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

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

int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.size() == 0)
        return 0;

    int freshOranges = 0;
    queue<vector<int>> q;

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (grid[row][col] == 2)
            {
                q.push({row, col});
            }
            if (grid[row][col] == 1)
            {
                freshOranges++;
            }
        }
    }

    int currQueueSize = q.size();
    int minutes = 0;
    while (q.size() > 0)
    {
        if (currQueueSize == 0)
        {
            minutes++;
            currQueueSize = q.size();
        }
        vector<int> currOrange = q.front();
        q.pop();
        currQueueSize--;
        int currRow = currOrange[0];
        int currCol = currOrange[1];
        for (int i = 0; i < direction.size(); i++)
        {
            vector<int> currDir = direction[i];
            int nextRow = currRow + currDir[0];
            int nextCol = currCol + currDir[1];

            if (nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size())
                continue;
            if (grid[nextRow][nextCol] == 1)
            {
                grid[nextRow][nextCol] = 2;
                q.push({nextRow, nextCol});
                freshOranges--;
            }
        }
    }
    if (freshOranges == 0)
        return minutes;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    cout << orangesRotting(grid);
    return 0;
}
