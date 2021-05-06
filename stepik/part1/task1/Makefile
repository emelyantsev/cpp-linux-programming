all: lib

exe: solution.h main.cpp lib
	g++ main.cpp -L. -lsolution -o main

lib: solution.cpp
	g++ -shared solution.cpp -o libsolution.so

clean:
	-rm main libsolution.so 2>/dev/null


# export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH