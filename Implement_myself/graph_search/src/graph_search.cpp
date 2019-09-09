#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

/**
 * Sample Graph
 (0) - (1) - (2) - (3)
              |     |
             (5)   (4)
              |    
             (6)
 */ 

const int MAX = 100;
const int map[7][7] = 
{   {0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0},

};
bool visited[MAX];
vector< vector<int> > graph;

void bfs(int idx, int val);
void dfs(int idx, int val);

void make_sample() {
    graph.clear();
    graph.resize(7);
    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++) 
            if(map[i][j] == 1) 
                graph[i].push_back(j);
}

void init() {
    make_sample();
    memset(visited, false, sizeof(visited));
    visited[0] = true;
}

void bfs(int idx, int val) {
    queue<int> q;
    q.push(idx);
    visited[idx] = true;

    while(!q.empty()) {
        int cur_node = q.front();
        q.pop();
        printf("node : %d\n", cur_node);
        if(cur_node == val) {
            printf("%d find!\n", val);
            break;
        }
        for(int i=0; i<graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i];
            if(visited[next_node]) continue;
            visited[next_node] = true;
            q.push(next_node);
        }
    }
}
void dfs(int idx, int val) {
    printf("node : %d\n", idx);
    for(int i=0; i<graph[idx].size(); i++) {
        int next_node = graph[idx][i];
        printf("[(%d)%d] Next Node: %d\n", graph[idx].size(), idx, next_node);
        if(visited[next_node]) continue;
        if(val == next_node) {
            printf("%d find! (%d, %d)\n", val, idx, i);
            return;
        }
        visited[next_node] = true;
        dfs(next_node, val);
        visited[next_node] = false;
    }
}

int main() {
    init();
    // dfs(0, 5);
    bfs(0, 5);
    return 0;
}