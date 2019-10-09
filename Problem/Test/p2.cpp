#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

deque<int> list;

void rolling(int C, int N) {
    deque<int> out_list;
    while(!(list.size() < 2 * N)) {
        for(int i=0; i<N; i++) {
            out_list.push_front(list.back());
            list.pop_back();
        }
        for(int i=N-1; i>=0; i--) out_list.push_front(list[i]);
         
        for(int i=0; i<N; i++) {
            list.pop_front();
        }
        
        /*for(int i=0; i<list.size(); i++) printf("%d ", list[i]);
        printf("\n");
        for(int i=0; i<out_list.size(); i++) printf("%d ", out_list[i]);
        printf("\n");*/
    }
    for(int i=0; i<out_list.size(); i++) list.push_back(out_list[i]);
}

int main() {
    freopen("p2_sample.txt", "r", stdin);

    int C, P, N;
    cin >> C;
    cin >> P;
    for(int i=1; i<=C; i++) list.push_back(i);
    for(int i=0; i<P; i++) {
        int N;
        cin >> N;
        rolling(C, N);
    }

    for(int i=0; i<5; i++) printf("%d\n", list[i]);

    return 0;
}