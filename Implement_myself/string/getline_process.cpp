#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> read_string_by_getline() {
    vector<string> list;

    while(true) {
        string in_string;
        getline(cin, in_string);
        if(in_string.empty()) break;
        list.push_back(in_string);
    }

    return list;
}

vector<string> my_string_tokenizer2() {
    vector<string> line = read_string_by_getline();
    // Process last word of line.
    // We split words using " " character. But, Last character is not " ". 
    // So, Add " " in last index of line.
    for(int i=0; i<line.size(); i++) line[i] += " "; 

    vector<string> words;
    for(int i=0; i<line.size(); i++) {
        int index = 0;
        for(int j = 0; j < line[i].length(); j++) 
            if(line[i][j] == ' ') {
                words.push_back(line[i].substr(index, j - index));
                index = j + 1;
            }
    }

    return words;
}

vector<string> my_string_tokenizer(vector<string> list) {
    vector<string> words;
    for(int i=0; i<list.size(); i++) {
        int index = 0;
        for(int j = 0; j < list[i].length(); j++) {
            if(list[i][j] == ' ') {
                words.push_back(list[i].substr(index, j - index));
                index = j + 1;
            }
        }
        // We split words using " " character. But, Last character is not " "
        // So, we have to process Last word individually.
        words.push_back(list[i].substr(index, list[i].length() - index));
    }
    return words;
}

int main() {
    freopen("../Samples/string_sample.txt", "r", stdin);
    //vector<string> line = read_string_by_getline();
    //vector<string> words = my_string_tokenizer(line);

    vector<string> words = my_string_tokenizer2();

    for(int i=0; i<words.size(); i++) 
       cout << words[i] << endl;
   
    return 0;
}