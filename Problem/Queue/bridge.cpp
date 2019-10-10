#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    for(int i=0; i<truck_weights.size(); i++) q.push(truck_weights[i]);
    
    int answer = 0;
    queue<pair<int, int>> bridge;
    int total_weight = 0;
    do {
        answer++;
        int size = bridge.size();
        for(int i=0; i<size; i++) {
            pair<int, int> cur = bridge.front();
            bridge.pop();

            if(cur.second != bridge_length - 1) 
                bridge.push({cur.first, cur.second+1});
            else 
                total_weight -= cur.first;
        }

        
        if(q.empty()) continue; 

        int cur = q.front();
        if(total_weight + cur <= weight) {
            total_weight += cur;
            bridge.push({cur, 0});
            q.pop();
        }
    } while(!bridge.empty());
    
    return answer;
}

int main() {
    vector<int> truck_weight;
    truck_weight.push_back(7);
    truck_weight.push_back(4);
    truck_weight.push_back(5);
    truck_weight.push_back(6);
    cout << solution(2, 10, truck_weight);
    return 0;
}