#include <string>
#include <vector>
#include <stack>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42588

int get_send_top(const vector<int> heights, int index) {
    int ret = 0;
    int cur = heights[index];
    for(int i=index-1; i>=0; i--) {
        if(heights[i] > cur) {
            ret = i+1;
            break;
        } 
    }
    return ret;
}

vector<int> solution(vector<int> heights) {
    stack<int> ret;
    for(int i=heights.size()-1; i>=0; i--) {
        int cnt = get_send_top(heights, i);
        ret.push(cnt);
    }
    vector<int> answer;
    while(!ret.empty()) {
        int cur = ret.top();
        answer.push_back(cur);
        ret.pop();
    }
    return answer;
}