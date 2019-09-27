#pragma once
#include <vector>

const int MAX = 100;
const int map[7][7] = 
{   {0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0},

}
bool visited[MAX][MAX];
vector< vector<int> > graph;

void bfs(int idx, int val);
void dfs(int idx, int val);