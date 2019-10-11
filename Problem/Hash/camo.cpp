#include <string>
#include <vector>
#include <map>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42578

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;
    
    if(clothes.empty()) return 0;
    
    for(int i=0; i<clothes.size(); i++) {
        if(m.count(clothes[i][1]) == 1) {
            m.find(clothes[i][1])->second++;
        }
        else m.insert({clothes[i][1], 1});
    }
    
    vector<int> clothes_count;
    for(auto it = m.begin(); it != m.end(); it++) {
        clothes_count.push_back(it->second);
    }
    
    int ret = 1;
    for(int i=0; i<clothes_count.size(); i++) {
        ret *= (clothes_count[i] + 1);
    }
    
    answer = ret - 1;
    return answer;
}