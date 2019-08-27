#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    freopen("../Samples/p10871_sample.txt", "r", stdin);

    int N, X;
    scanf("%d %d", &N, &X);

    vector<int> ret;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        if(num < X) ret.push_back(num);
    }

    for(int i=0; i<ret.size(); i++) printf("%d ", ret[i]);
    printf("\n");

    return 0;
}