#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
bool visited[MAX];
int d[2] = {-1, 1};

bool in_range(int x) { return x>=0 && x<MAX; }

int bfs(int start, int dest) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    int time = 0;
    while(!q.empty()) {
        int cur_pos = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        if(cur_pos == dest) {
            time = cur_time;
            break;
        }
    
        for(int i=0; i<3; i++) {
            int next;
            if(i==2) next = cur_pos * 2;
            else next = cur_pos + d[i];
            if(!in_range(next) || visited[next]) continue;
            visited[next] = true;
            q.push({next, cur_time+1});
        }
    }
    
    return time;
}
 
int main() {
    freopen("../Samples/p1697_sample.txt", "r", stdin);
    int N, K;
    scanf("%d %d", &N, &K);
    
    memset(visited, false, sizeof(visited));

    int ret = bfs(N, K);

    printf("%d\n", ret);
    return 0;
}