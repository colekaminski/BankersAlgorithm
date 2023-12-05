# BankersAlgorithm

Operating Systems Fall 2023 Cole Kaminski 12/1/2023

//PURPOSE
The purpose of this project is to determine if a Banker's algorithm is in a safe state, and then determine a safe sequence if applicable.
The system includes five processes (P0 through P4) and three resources (A,B,C). There are 10 instances of resource A, 5 of resource B, and 7 of resource C.
The Banker's algorithm is intended to avoid deadlock and allocate resources safely to each process in the computer system. It is also known as a deadlock avoidance algorithm
because the operating system must determine which process sequence should be executed or waited so deadlock does not occur. 

//USAGE
The code works by reading in from a file (input.txt), storing the values as integers in a vector, and reversing said vector in order to retrieve the correct sequence of numbers. Then, 3 matrices are created to sroe values for an allocated, max, and needed tables. The functions determine if a process can run with the available resources and places the processes into the best available spot in the path. The program ends by outputting a safe sequence.

Consider the follwing comman prompts to execute the program:
g++ banker.cpp -o bankers
./bankers
