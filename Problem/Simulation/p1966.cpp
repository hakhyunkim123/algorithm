#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool compare(int x, int y) { return x > y; }

int solution(vector<int> priorities, int location) {
    deque<int> dq, order;
    for(int i=0; i<priorities.size(); i++) {
        dq.push_back(priorities[i]);
        order.push_back(priorities[i]);
    }

    sort(order.begin(), order.end(), compare);

    int answer = 0, ret_p = dq[location];
    dq[location] = -1;

    while(true) {
        bool finish = false;
        for(int i=0; i<dq.size(); i++) {
            if(dq.front() == -1) {
                if(order.front() == ret_p) {
                    finish = true;
                    answer++;
                    break;
                }
                else {
                    dq.pop_front();
                    dq.push_back(-1);
                }
            }
            else {
                if(dq.front() == order.front()) {
                    dq.pop_front();
                    order.pop_front();
                    answer++;
                    break;
                }
                else {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
        }
        if(finish) break;
    }
    return answer;
}

int main() {
    freopen("../Samples/p1966_sample.txt", "r", stdin);
    int test_case;
    scanf("%d", &test_case);

    for(int tc = 1; tc <= test_case; tc++) {
        deque<int> dq, order;
        int N, M;
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; i++) {
            int p; scanf("%d", &p);
            dq.push_back(p);
            order.push_back(p);
        }

        sort(order.begin(), order.end(), compare);

        int cnt = 0, ret_p = dq[M];
        dq[M] = -1;
        while(true) {
            bool finish = false;
            for(int i=0; i<dq.size(); i++) {
                if(dq.front() == -1) {
                    if(order.front() == ret_p) {
                        finish = true;
                        cnt++;
                        break;
                    }
                    else {
                        dq.pop_front();
                        dq.push_back(-1);
                    }
                }
                else {
                    if(dq.front() == order.front()) {
                        dq.pop_front();
                        order.pop_front();
                        cnt++;
                        break;
                    }
                    else {
                        dq.push_back(dq.front());
                        dq.pop_front();
                    }
                }
            }
            if(finish) break;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
