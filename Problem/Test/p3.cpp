#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    freopen("p3_sample.txt", "r", stdin);
    int day;
    cin >> day;
    vector<int> price_list;
    price_list.resize(day);
    for(int i=0; i<day; i++) 
        cin >> price_list[i];

    int sum = 0, income = 0, max = price_list[day-1];
    for(int i=day-2; i>=0; i--) {
        if(max < price_list[i]) {
            max = price_list[i];
            if(income != 0) sum += (income - 1);
            income = 0;
        }
        else 
            income += (max - price_list[i]);
    }

    if(income > 0) sum += (income - 1);

    cout << sum << endl;

    return 0;
}