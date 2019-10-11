#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42577

bool compare_number(string num1, string num2) {
    bool ret = true;
    int small_length = min(num1.length(), num2.length());
    for(int i=0; i<small_length; i++) {
        if(num1[i] != num2[i]) {
            ret = false;
            break;
        }
    }
    return ret;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size(); i++) {
        bool success = false;
        for(int j=i+1; j<phone_book.size(); j++) {
            if(compare_number(phone_book[i], phone_book[j])) {
                success = true;
                break;
            }
        }
        if(success) {
            answer = false;
            break;
        }
    }
    return answer;
}