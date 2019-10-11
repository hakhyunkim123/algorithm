#include <string>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/43162

const int MAX = 200;
bool visited[MAX];

void dfs(int node, vector<vector<int>> graph) {
    visited[node] = true;
    
    for(int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if(visited[next]) continue;
        dfs(next, graph);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<vector<int>> graph;
    graph.resize(n);
    
    for(int i=0; i<computers.size(); i++) {
        for(int j=0; j<computers[i].size(); j++) {
            if(i != j && computers[i][j]) graph[i].push_back(j);
        }
    }
    
    int answer = 0;
    memset(visited, false, sizeof(visited));
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, graph);
            answer++;
        }
    }
    return answer;
}