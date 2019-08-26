Simulate Sort Algorithms
=========================

make static lib
---------------
#### (example)
##### g++ -c .\src\sampling.cpp -o .\obj\sampling.o
##### g++ -c .\src\my_sort.cpp -o .\obj\my_sort.o
##### ar -r .\lib\libsort.a .\obj\my_sort.o .\obj\sampling.o
##### g++ -o out .\src\main.cpp -L.\lib\ -lsort