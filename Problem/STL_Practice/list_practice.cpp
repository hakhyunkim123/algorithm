#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

bool predicate(int num) {
    return num >= 5;
}

int main() {
    list<int> numbers;

    for(int i=0; i<10; i++) numbers.push_back(i+1);
    for(int i=0; i<10; i++) numbers.push_back(i+1);
    
    numbers.remove(5);

    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        if(*it == 6) {
            numbers.insert(it, 5);
            break;
        }
    }

    numbers.sort(greater<int>());
    numbers.unique();
    numbers.remove_if(predicate);

    list<int>::iterator it;
    for(it = numbers.begin(); it != numbers.end(); it++) printf("%d ", *it);
    printf("\n");

    return 0;
}