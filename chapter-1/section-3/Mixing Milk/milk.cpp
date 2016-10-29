/*
ID: rahul.y1
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("milk.in");
	if(!in) {
		cout << "Couldn't open milk.in";
		return 1;
	}
	ofstream out("milk.out");
	if(!out) {
		cout << "Couldn't create milk.out";
		return 1;
	}

	int N;
	int M;
	int *P;
	int *A;
	
	in >> N;
	in.ignore(1,' ');
	in >> M;
	P = new int[M];
	A = new int[M];

	for(int i=0; i<M; i++) {
		in.ignore(1, '\n');
		in >> P[i];
		in.ignore(1, ' ');
		in >> A[i];
	}
	in.close();

	// sorts the farmers in order of price
	for(int i=0; i<M; i++) {
		for(int j=0; j<M-i-1; j++) {
			if(P[j]>P[j+1]) {
				int temp = P[j];
				P[j] = P[j+1];
				P[j+1] = temp;
				temp = A[j];
				A[j]=A[j+1];
				A[j+1] = temp;
			}
		}
	}

	// print sorted arrays
	//for(int i=0; i<M; i++) {
	//	cout << P[i] << " " << A[i] << "\n";
	//}

	// adds onto price until N=0
	int price=0;
	int curFarmer = 0;
	while(N>0) {
		if(A[curFarmer]>=N) {
			price+=N*P[curFarmer];
			N=0;
		}
		else {
			price+=A[curFarmer]*P[curFarmer];
			N-=A[curFarmer];
		}
		curFarmer++;
	}

	out << price << "\n";
	return 0;
}