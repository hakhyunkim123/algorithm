#include <string>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42841

vector<string> num_list;
bool visited[10];
vector<string> ret;

bool check(const string num, const vector<vector<int>> baseball) {
    bool ret = true;
    for(int idx=0; idx<baseball.size(); idx++) {
        int s = 0, b = 0;
        string compare_number = to_string(baseball[idx][0]);
        for(int i=0; i<3; i++) 
            for(int j=0; j<3; j++) 
                if(num[i] == compare_number[j]) i == j ? s++ : b++;
     
        if(baseball[idx][1] != s || baseball[idx][2] != b) {
            ret = false;
            break;
        }
    }
    return ret;
}

void set_number(string num, int depth, vector<vector<int>> baseball) {
    if(depth == 0) {
        if(check(num, baseball)) ret.push_back(num);
        return;
    }
    
    for(int i=0; i<num_list.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            set_number(num + num_list[i], depth-1, baseball);
            visited[i] = false;
        }
    }
}

int solution(vector<vector<int>> baseball) {
    for(int i=1; i<10; i++) num_list.push_back(to_string(i));
    
    for(int i=0; i<num_list.size(); i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        set_number(num_list[i], 2, baseball);
        visited[i] = false;
    }
    
    int answer = ret.size();
    return answer;
}