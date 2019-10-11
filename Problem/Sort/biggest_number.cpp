#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42746

bool compare(const string& a, const string& b) {
    if(a[0] == b[0]) {
        return a+b > b+a;
    }
    else {
        return a[0] > b[0];
    }
}

string solution(vector<int> numbers) {
    vector<string> numbers_string;
    for(int i=0; i<numbers.size(); i++) {
        numbers_string.push_back(to_string(numbers[i]));
    }
    
    sort(numbers_string.begin(), numbers_string.end(), compare);
    
    string answer = "";
    for(int i=0; i<numbers_string.size(); i++) {
        answer += numbers_string[i];
    }
    if(answer[0] == '0') answer = "0";
    return answer;
}