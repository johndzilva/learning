// 207. Course Schedule
// Medium

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
//  You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
//   take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto i : prerequisites)
    {
        indegree[i[0]]++;
        adj[i[1]].push_back(i[0]);
    }
    stack<int> st;
    int count = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            st.push(i);
        }
    }
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        count++;
        for (auto i : adj[curr])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                st.push(i);
            }
        }
    }

    return count == numCourses;
}

void canFinish_optimized(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(numCourses, 0);
    int count = 0;
    stack<int> st;
    for (auto i : prerequisites)
    {
        indegree[i[0]]++;
    }
    for (auto i : indegree)
    {
        if (i == 0)
        {
            st.push(i);
        }
    }
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        count++;
        for (auto i : prerequisites)
        {
            if (i[1] == curr)
            {
                indegree[i[0]]--;
                if (indegree[i[0]] == 0)
                {
                    st.push(i[0]);
                }
            }
        }
    }

    return count == numCourses;
}

int main(int argc, char const *argv[])
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

    cout << canFinish_optimized(numCourses, prerequisites) << endl;
    return 0;
}
