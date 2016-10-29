/*
ID: rahul.y1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int N;

int leftCycle(int leftPoint, string &beads);
int rightCycle(int leftPoint, int numLeft, string beads);

int main()
{
	// declarations
	string beadsOrig;
	int maxNum=0;

	// open file
	ifstream in("beads.in");
	if(!in) {
		cout << "Cannot open beads.in\n";
		return 1;
	}
	ofstream out("beads.out");
	if(!out) {
		cout << "Cannot open beads.out\n";
		return 1;
	}

	// gets N, the number of beads
	in >> N;
	in.ignore(1, '\n');

	// gets the string
	getline(in, beadsOrig, '\n');
	// closes the input file
	in.close();

	// test start points
	for(int i=0; i<N; i++) {
		string beads = beadsOrig;
		int numLeft;
		int numRight;
		
		numLeft = leftCycle(i, beads);
		cout << numLeft << "\n";
	//	cout << "beads length: " << beads.length() << "\n";
		/*if(numLeft+i>N) {
			beads.erase(i);
			beads.erase(0, numLeft-N+i);
		}
		else {
			beads.erase(i, numLeft);
		}*/
	//	cout << i << ". " << numLeft << "\n" << beads << "\n";
		
		numRight = rightCycle(i, numLeft, beads);
		cout << numRight << "\n\n";
		if(maxNum < numLeft+numRight) {
			maxNum = numLeft+numRight;
		}
	//	cout << numRight << "\n" << beads << "\n";
	}

	out << maxNum << '\n';
	out.close();
	return 0;
}

int leftCycle(int leftPoint, string &beads)
{
	int numLeft=0;
	bool repeat=true;
	char left = beads[leftPoint];
	
	while(left=='w'/* && numLeft<=N*/) {
		beads[leftPoint]='a';
		leftPoint++;
		numLeft++;
		left=beads[leftPoint];
	}

	//if(numLeft==N) {return numLeft;}

	for(int i=0; (i<beads.length()) && (repeat); i++) {
		if(beads[(leftPoint+i)%N]==left || beads[(leftPoint+i)%N]=='w') {
			numLeft++;
			beads[(leftPoint+i)%N]='a';
		}
		else {
			repeat = false;
		}
	}

	//for(int i=0; i<beads.length(); i++) {
	//	if(beads[i]=='a') {
	//		beads.erase(i,1);
	//	}
	//}
	return numLeft;
}

int rightCycle(int leftPoint, int numLeft, string beads)
{
	int rightPoint;
	int numRight=0;
	char right;
	bool repeat=true;

	if(!(beads.length()==0)) {
		/*if(numLeft+leftPoint>N-1) {
			rightPoint = beads.length()-1;
		}
		else {
			if(leftPoint == 0) {
				rightPoint = beads.length()-1;
			}
			else {
				rightPoint = leftPoint-1;
			}
		}*/
		rightPoint = leftPoint-1;

		right = beads[rightPoint];
		while(right=='w') {
			beads[rightPoint]='a';
			rightPoint=(rightPoint-1)%(N);
			if(rightPoint<0) {rightPoint+=N;}
			numRight++;
			right=beads[rightPoint];
			if(right=='a') return 1;
		}
		for(int k=0; (k<beads.length()) && repeat; k++) {
			int index = (rightPoint-k)%N;
			if(index<0) {index+=N;}
			if(beads[index]=='a') continue;
			if((beads[index]==right) || (beads[index]=='w')) {
				numRight++;
			}
			else {
				repeat=false;
			}
		}

		return numRight;
	}
	else {
		return 0;
	}
}