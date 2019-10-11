#include <string>
#include <vector>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/43165

const int op[2] = {-1, 1};

int dfs(int depth, int sum, vector<int> numbers,int target) {
    if(depth == numbers.size()) {
        if(sum == target) return 1;
        return 0;
    }    
    int ret = 0;
    for(int i=0; i<2; i++) {
        ret += dfs(depth+1, sum + numbers[depth] * op[i], numbers, target);
    }
    
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(0, 0, numbers, target);
    return answer;
}