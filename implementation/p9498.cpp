#include <iostream>

using namespace std;

int main() {
    int score;
    cin >> score;

    char ret;
    if (score >= 90 && score <=100) ret = 'A';
    else if (score >= 80 && score <= 89) ret = 'B';
    else if (score >= 70 && score <= 79) ret = 'C';
    else if (score >= 60 && score <= 69) ret = 'D';
    else ret = 'F';
   
    cout << ret << endl;
    return 0;
}