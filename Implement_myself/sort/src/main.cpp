#include <iostream>
#include <fstream> 
#include "../include/sampling.h"
#include "../include/my_sort.h"
using namespace std;

int main() {
    /*int ary[10];
    sampling(10);

    sample_reading(ary, 10);
    print_ary(ary, 10);

    int res[10];
    copy_ary(res, ary, 10);
    insertion_sort(res, 10);
    print_ary(res, 10);

    ofstream res_file("./result/result.txt");
    if(res_file.is_open()) 
        for(int i=0; i<10; i++) res_file << res[i] << " ";
    else 
        cout << "res file is not open." << endl;
    res_file.close();*/


    const int sample_size = 50000;
    int sample[sample_size];
    sampling(sample_size);

    sample_reading(sample, sample_size);
    self_test(sample, sample_size);

    return 0;
}