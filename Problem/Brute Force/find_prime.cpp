#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42839

bool visited[10];
bool number[10000000];
string in_str = "011";
vector<string> decimal;

bool is_prime(int num) {
    if(num <= 1) return false;
    
    bool ret = true;
    for(int i = 2; i < num; i++) 
        if(num % i == 0) {
            ret = false;
            break;
        }
    
    return ret;
}

int count_prime(string num, int depth, int last) {
    if(depth > last) return 0;

    int ret = 0;
    int str_to_num = atoi(num.c_str());
    if(!number[str_to_num] && is_prime(str_to_num)) ret++;
    
    number[str_to_num] = true;

    for(int i=0; i<decimal.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            ret += count_prime(num + decimal[i], depth+1, last);
            visited[i] = false;
        }
    }

    return ret;
}

int main() {
    for(int i=0; i<in_str.length(); i++) {
        string num(1, in_str[i]);
        decimal.push_back(num);
    }

    int ans = 0;
    memset(number, false, sizeof(number));
    for(int i=0; i<decimal.size(); i++) {
        memset(visited, false, sizeof(visited));

        visited[i] = true;
        ans += count_prime(decimal[i], 1, decimal.size());
        visited[i] = false;
    }

    cout << ans << endl;
    
    return 0;
}