SRCS = src/main.cpp

program: 
	g++ -o main $(SRCS) -Ilib -g -O0 -Wall -Wextra -Wpedantic