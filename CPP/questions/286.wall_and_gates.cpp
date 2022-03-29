// 286. Walls and Gates
// Medium
// Description
// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

// Example
// Example1

// Input:
// [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output:
// [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

// Explanation:
// the 2D grid is:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// the answer is:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 2147483647;
int GATE = 0;
int WALL = -1;

vector<vector<int>> direction{
    {-1, 0}, // up
    {0, 1},  // right
    {1, 0},  // down
    {0, -1}, // left
};

void dfs(vector<vector<int>> &rooms, int row, int col, int distance)
{
    if (row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size() || rooms[row][col] < distance)
        return;

    rooms[row][col] = distance;

    for (auto i : direction)
    {
        vector<int> currDir = i;
        dfs(rooms, row + currDir[0], col + currDir[1], distance + 1);
    }
}
void wallsAndGates(vector<vector<int>> &rooms)
{
    for (int row = 0; row < rooms.size(); row++)
    {
        for (int col = 0; col < rooms[0].size(); col++)
        {
            if (rooms[row][col] == GATE)
            {
                dfs(rooms, row, col, 0);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> rooms = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}};

    wallsAndGates(rooms);

    for (auto a : rooms)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
