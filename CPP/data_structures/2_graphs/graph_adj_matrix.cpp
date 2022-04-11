#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int NODE = 7;
int EDGE = 8;

void print_dfs(vector<vector<int>> &data, int startVertex, vector<bool> &visited)
{
    cout << startVertex << endl;
    visited[startVertex] = true;
    int n = data.size();
    for (int i = 0; i < n; i++)
    {
        if (data[startVertex][i] == 1 && visited[i] == false)
        {
            print_dfs(data, i, visited);
        }
    }
}

void print_bfs(vector<vector<int>> &data, int startVertex, vector<bool> &visited)
{
    cout << startVertex << endl;
    visited[startVertex] = true;
    queue<int> q;
    q.push(startVertex);
    while (!q.empty())
    {
        int currVertex = q.front();
        q.pop();
        for (int i = 0; i < data.size(); i++)
        {
            if (data[currVertex][i] == 1 && visited[i] == false)
            {
                cout << i << endl;
                visited[i] = true;
                q.push(i);
            }
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
    print_dfs(matrix, 0, visited);
    fill(visited.begin(), visited.end(), false);
    cout << "BFS:" << endl;
    print_bfs(matrix, 0, visited);
    return 0;
}
