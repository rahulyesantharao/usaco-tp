/*
ID: rahul.y1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

char before[10][10];
char after[10][10];
int N;

void rotate(char (*temp)[10]);
void reflect(char (*temp)[10]);
bool equal(char (*op1)[10], char (*op2)[10]);
int main()
{
	// open input file
	ifstream in("transform.in");
	if(!in) {
		cout << "Couldn't open file transform.in";
		return 1;
	}
	ofstream out("transform.out");
	if(!out) {
		cout << "Couldn't open file transform.out";
		return 1;
	}

	// input N
	in >> N;
	in.ignore(1, '\n');

	//input before array
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			in >> before[i][j];
		}
		in.ignore(1, '\n');
	}

	// input after array
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			in >> after[i][j];
		}
		in.ignore(1, '\n');
	}
	// close input file
	in.close();


	///////////////////////////////////////////////////////////////////
	// 1: rotate^1
	// 2: rotate^2
	// 3: rotate^3
	// 4: reflect
	// 5: reflect(rotate^n), 1<=n<=3
	// 6: N/A
	// 7: none of the above
	///////////////////////////////////////////////////////////////////
	int min = 8;
	// 6
	if(min>6) {
		if(equal(before,after)) { min=6; }
	}
	// 1
	rotate(before);
	if(min>1) {
		if(equal(before,after)) { min=1; }
	}
	// 5
	reflect(before);
	if(min>5) {
		if(equal(before,after)) { min=5; }
	}
	// 2
	reflect(before);
	rotate(before);
	if(min>2) {
		if(equal(before,after)) { min=2; }
	}
	// 5
	reflect(before);
	if(min>5) {
		if(equal(before,after)) { min=5; }
	}
	// 3
	reflect(before);
	rotate(before);
	if(min>3) {
		if(equal(before,after)) { min=3; }
	}
	// 5
	reflect(before);
	if(min>5) {
		if(equal(before,after)) { min=5; }
	}
	// 4
	reflect(before);
	rotate(before);
	reflect(before);
	if(min>4) {
		if(equal(before,after)) { min=4; }
	}

	if(min==8) min=7;

	out << min << "\n";
	return 0;
}

void rotate(char (*temp)[10])
{
	int temp2[10][10];
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			temp2[i][j] = temp[i][j];
		}
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			temp[j][N-i-1] = temp2[i][j];
		}
	}

}

void reflect(char (*temp)[10])
{

	if((N%2)==0) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<(N/2); j++) {
				int holder = temp[i][N-1-j];
				temp[i][N-1-j] = temp[i][j];
				temp[i][j] = holder;
			}
		}
	}
	else {
		for(int i=0; i<N; i++) {
			for(int j=0; j<((N-1)/2); j++) {
				int holder = temp[i][N-1-j];
				temp[i][N-1-j] = temp[i][j];
				temp[i][j] = holder;
			}
		}
	}
}

bool equal(char (*op1)[10], char (*op2)[10])
{
	for(int i=0; ((i<N)); i++) {
		for(int j=0; (j<N); j++) {
			if(op1[i][j]!=op2[i][j]) {
				return false;
			}
		}
	}
	return true;
}