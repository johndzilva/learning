// using adj list

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int numberOfVertices;
    list<int> *adj;
    bool *visited;
    bool isDirected;

public:
    Graph(int numberOfVertices, bool isDirected)
    {
        this->numberOfVertices = numberOfVertices;
        this->isDirected = isDirected;
        adj = new list<int>[numberOfVertices];
        visited = new bool[numberOfVertices];
    }

    void deleteVisited()
    {
        for (int i = 0; i < numberOfVertices; i++)
        {
            visited[i] = false;
        }
    }

    void addEdge(int source, int destination)
    {
        adj[source].push_back(destination);
        if (!isDirected)
        {
            adj[destination].push_back(source);
        }
    }

    void dfs(int vertex)
    {
        visited[vertex] = true;
        cout << vertex << " ";
        for (auto i : adj[vertex])
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
    }

    void bfs(int vertex)
    {
        visited[vertex] = true;
        cout << vertex << " ";
        queue<int> q;
        q.push(vertex);
        while (!q.empty())
        {
            int currVertex = q.front();
            q.pop();
            for (auto i : adj[currVertex])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    cout << i << " ";
                    q.push(i);
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(7, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    cout << "DFS: ";
    g.dfs(0);
    cout << endl;

    g.deleteVisited();
    cout << "BFS: ";
    g.bfs(0);

    return 0;
}
