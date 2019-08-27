sort_out : .\obj\main.o .\obj\my_sort.o .\obj\sampling.o
	g++ -o sort_out .\obj\main.o .\obj\sampling.o .\obj\my_sort.o
	# make static library
	ar -r .\lib\libsort.a .\obj\my_sort.o .\obj\sampling.o 

main.o: .\include\my_sort.h .\include\sampling.h .\src\main.cpp
	g++ -c -o .\obj\main.o .\src\main.cpp

my_sort.o : .\include\my_sort.h .\src\my_sort.cpp
	g++ -c -o .\obj\my_sort.o .\src\my_sort.cpp

sampling.o : .\include\sampling.h .\src\sampling.cpp
	g++ -c -o .\obj\sampling.o .\src\sampling.cpp

