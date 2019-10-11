#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42586

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    deque<pair<int, int> > dq;
    vector<int> answer;
    
    for(int i=0; i<progresses.size(); i++) 
        dq.push_back(make_pair(progresses[i], speeds[i]));
    
    while(!dq.empty()) {
        for(int i=0; i<dq.size(); i++) 
            dq[i].first += dq[i].second;
        
        int size = dq.size();
        int cnt = 0;
        while(!dq.empty() && dq.front().first >= 100) {
            cnt++;
            dq.pop_front();
        }
        if(cnt > 0) answer.push_back(cnt);
    }
    return answer;
}