#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> list;

    for(int i=1; i != 10; i++) list.push_back(i);

    /*vector<int>::iterator it;
    for(it = list.begin(); it != list.end(); it++) {
        if(*it == 5) {
            list.erase(it, list.end());
            break;
        }
    }*/
    vector<int>::iterator it;
    for(it = list.begin(); it != list.end(); it++) 
        if(*it == 5) list.erase(it);
    
    for(int i=0; i<list.size(); i++) 
        cout << list[i] << " ";
    cout << endl;

    return 0;
}