//Cole Kaminski
//Operating Systems
///12/1/2023
//Bankers Algorithm Project c++ file

#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int processes = 5;
const int resources = 3;

int fillMatrix(int [processes][resources], vector<int>&);

int main() {
   	vector<int> info;	//Creates vector to read information from file
	char ch;
	std::ifstream input ("input.txt");
	if(!input.is_open()) {						//Making sure the file is opened
		std::cout << "Unable to open file\n";	
		return 0;
	}
	input >> ch;
	while(!input.eof()) {	//Reads until end of file
		if(ch == ':') {
			input >> ch;
			while(ch != ';') {		//Moves all the characters that are in between : and ; into the vector
				info.push_back(static_cast<int>(ch - '0'));	//Making the conversion from character to integer correct for the numbers
				input >> ch;
			}
		}
		input >> ch;
	}
	std::cout << "\n";
	input.close();		//Closes file



	reverse(info.begin(),info.end());	//Reverses vector of information
	
	int allocated[processes][resources];	//Creates 3 matrices for allocated, max, needed, and an array for available
	int max[processes][resources];
	int needed[processes][resources];
	int available[resources];



	fillMatrix(allocated, info);	//Fills in allocated matrix
	fillMatrix(max, info);		//Fills in max matrix

	int a = 0;
	while(a < resources) {
		available[a] = info.back();	//Puts the rest of the info in vector into available resources array
		info.pop_back();
		a++;
	}

	int b = 0;
	int c = 0;
	while(b < processes) {		//Finds the needed matrix from the max and allocated matrices
		c = 0;
		while(c < resources) {
			needed[b][c] = max[b][c] - allocated[b][c];
			c++;
		}
		b++;
	}

	int finished[processes], path[processes], x = 0;	//Creates array to hold which processes still have to finish, and what path is safe
	int i, j, k, y;
	for (k = 0; k < processes; k++) {
		finished[k] = 0;
	}
	for (k = 0; k < 5; k++) {
		for (i = 0; i < processes; i++) {
			if (finished[i] == 0) {
				int flag = 0;
				for (j = 0; j < resources; j++) {	//Checks if a process could run with the available resources
					if (needed[i][j] > available[j]){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {	//If process could run with available resources
					path[x++] = i;	//Places process into the next spot in the path to run
					for (y = 0; y < resources; y++) {
						available[y] += allocated[i][y];	//Puts allocated resources into available
					}
					finished[i] = 1;	//Changes the status of this process to finished
				}
			}
		}
	}
	std::cout << "The following is the safe sequence for the processes to run:\n";
	for (i = 0; i < (processes - 1); i++) {
		std::cout << " P" << path[i] << " ->";		//Prints the safe sequence for the processes to run
	}
	std::cout << " P" << path[processes - 1] << "\n";

	return 0;
}


int fillMatrix(int matrix[processes][resources], vector<int>& info) {	//Function to fill a matrix
	int i = 0;
	int j = 0;
	while(i < processes) {
		j = 0;
		while(j < resources) {
			matrix[i][j] = info.back();
			info.pop_back();
			j++;
		}
		i++;
	}
	return 0;
}


