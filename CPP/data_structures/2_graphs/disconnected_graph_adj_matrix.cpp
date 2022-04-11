#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int NODE = 8;
int EDGE = 6;

void print_disconnected_dfs(vector<vector<int>> &data, int startVertex, vector<bool> &visited)
{
    cout << startVertex << endl;
    visited[startVertex] = true;
    int n = data.size();
    for (int i = 0; i < n; i++)
    {
        if (data[startVertex][i] == 1 && visited[i] == false)
        {
            print_disconnected_dfs(data, i, visited);
        }
    }
}

void dfs(vector<vector<int>> &data)
{
    vector<bool> visited(NODE, false);
    for (int i = 0; i < NODE; i++)
    {
        if (visited[i] == false)
        {
            print_disconnected_dfs(data, i, visited);
        }
    }
}

void print_disconnected_bfs(vector<vector<int>> &data, int startVertex, vector<bool> &visited)
{
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;
    while (!q.empty())
    {
        int currVertex = q.front();
        q.pop();
        cout << currVertex << endl;
        for (int i = 0; i < visited.size(); i++)
        {
            if (data[currVertex][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void bfs(vector<vector<int>> &data)
{
    vector<bool> visited(NODE, false);
    for (int i = 0; i < NODE; i++)
    {
        if (!visited[i])
        {
            print_disconnected_bfs(data, i, visited);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix(NODE, vector<int>(NODE, 0));
    vector<bool> visited(NODE, false);

    for (int i = 1; i <= EDGE; i++)
    {
        int firstVertex, secondVertex;
        cout << "Enter the first vertex and second vertex: ";
        cin >> firstVertex >> secondVertex;
        matrix[firstVertex][secondVertex] = 1;
        matrix[secondVertex][firstVertex] = 1;
    }
    cout << "DFS:" << endl;
    dfs(matrix);
    cout << "BFS:" << endl;
    bfs(matrix);

    return 0;
}
