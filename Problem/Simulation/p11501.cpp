#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> price_list;

int main() {
    //freopen("../Samples/p11501_sample.txt", "r", stdin);
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        price_list.clear();
        cin >> N;

        for(int i=0; i<N; i++) {
            int price;
            cin >> price;
            price_list.push_back(price);
        }

        int max_price = price_list[N-1];
        unsigned long long ret = 0;
        for(int i=N-2; i>=0; i--) {
            if(price_list[i] > max_price) max_price = price_list[i];
            else ret += max_price - price_list[i];
        }
        cout << ret << endl;
    }
}