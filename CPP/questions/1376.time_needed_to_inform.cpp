// 1376. Time Needed to Inform All Employees
// Medium

// A company has n employees with a unique ID for each employee from 0 to n - 1.
//  The head of the company is the one with headID.
// Each employee has one direct manager given in the manager array where manager[i]
//  is the direct manager of the i-th employee, manager[headID] = -1. Also, it is
//  guaranteed that the subordination relationships have a tree structure.
// The head of the company wants to inform all the company employees of an urgent
// piece of news. He will inform his direct subordinates, and they will inform their
//  subordinates, and so on until all employees know about the urgent news.
// The i-th employee needs informTime[i] minutes to inform all of his direct subordinates
//  (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).
// Return the number of minutes needed to inform all the employees about the urgent news.

// Example 1:

// Input: n = 1, headID = 0, manager = [-1], informTime = [0]
// Output: 0
// Explanation: The head of the company is the only employee in the company.

// Example 2:

// Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
// Output: 1
// Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
// The tree structure of the employees in the company is shown.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int dfs(int currId, unordered_map<int, vector<int>> adj_list, vector<int> informTime)
{
    if (adj_list[currId].empty())
        return 0;

    int maxTime = 0;
    vector<int> children = adj_list[currId];
    for (int child : children)
    {
        int time = dfs(child, adj_list, informTime);
        maxTime = max(maxTime, time);
    }
    return maxTime + informTime[currId];
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    unordered_map<int, vector<int>> adj_list;
    for (int i = 0; i < n; i++)
    {
        if (manager[i] != -1)
        {
            adj_list[manager[i]].push_back(i);
        }
    }
    return dfs(headID, adj_list, informTime);
}

int main(int argc, char const *argv[])
{
    vector<int> manager = {2, 2, -1, 2, 2, 2};
    vector<int> informTime = {0, 0, 1, 0, 0, 0};

    cout << numOfMinutes(6, 2, manager, informTime) << endl;

    return 0;
}
