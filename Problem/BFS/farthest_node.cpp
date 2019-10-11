#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/49189

const int MAX = 20001;

bool visited[MAX];

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph;
    graph.resize(n+1);
    for(int i=0; i<edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    visited[1] = true;
    int max_depth = 0, max_cnt = 0;
    while(!q.empty()) {
        int cur_node = q.front().first;
        int cur_depth = q.front().second;
        q.pop();
        
        int next_cnt = 0;
        for(int i=0; i<graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i];
            if(!visited[next_node]) {
                visited[next_node] = true;
                q.push(make_pair(next_node, cur_depth+1));
                next_cnt++;
            }
        }
        if(!next_cnt) {
            if(cur_depth == max_depth) {
                max_cnt++;
            }
            else if(cur_depth > max_depth) {
                max_depth = cur_depth;
                max_cnt = 1;
            }
        }
    }
    int answer = max_cnt;
    return answer;
}