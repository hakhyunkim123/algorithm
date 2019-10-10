#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int brown, int x, int y) {
    if(y<3) return false;
    return brown == (x*2 + (y-2)*2);
}

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int area = brown + red;
    bool success = false;
    for(int x = area/3; x>=3; x--) {
        if(area % x == 0) success = check(brown, x, area / x);
        if(success) {
            answer.push_back(x);
            answer.push_back(area / x);
            break;
        }
    }
    return answer;
}