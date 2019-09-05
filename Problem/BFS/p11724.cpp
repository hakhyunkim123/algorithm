#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;
vector< vector<int> > graph;
bool visited[MAX];

void bfs(int start_idx) {
    queue<int> q;
    q.push(start_idx);
    visited[start_idx] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return;
}

int main() {
    freopen("../Samples/p11724_sample.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    graph.resize(N+1);
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    int comp = 0;
    for(int i=1; i<graph.size(); i++) {
        if(visited[i]) continue;
        bfs(i);
        comp++;
    }
    printf("%d\n", comp);
    return 0;
}