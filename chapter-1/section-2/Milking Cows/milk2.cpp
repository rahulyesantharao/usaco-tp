/*
ID: rahul.y1
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

// function declarations
void sort();
void merge1(int i);
void merge2(int i);

// global variables
int N;
int *startTimes;
int *endTimes;

int main()
{
	// input number of farmers
	ifstream in("milk2.in");
	if(!in) {
		cout << "Could not open file milk2.in";
		return 1;
	}
	ofstream out("milk2.out");
	if(!out) {
		cout << "Could not open file milk2.out";
		return 1;
	}

	in >> N;
	in.ignore(1, '\n');

	// allocate arrays
	startTimes = new int[N];
	endTimes = new int[N];

	// input arrays
	for(int i=0; i<N; i++) {
		in >> startTimes[i];
		in >> endTimes[i];
		in.ignore(1, '\n');
	}

	// close input file
	in.close();
	
	// sort by starting times
	sort();
	
	for(int i=0; i<N-1; i++) {
		if((startTimes[i]<=startTimes[i+1]) && (endTimes[i]>=endTimes[i+1])) {
			merge2(i);
			continue;
		}
		if(endTimes[i]>=startTimes[i+1]) {
			merge1(i);
		}
	}
	
	for(int i=0; i<N; i++) {
		cout << startTimes[i] << " " << endTimes[i] << "\n";
	}

	int curMilkLength = 0;
	int maxLength = 0;
	int curNoMilk = 0;
	int maxNoMilk = 0;
	for(int i=0; i<N-1; i++) {
		if((startTimes[i]==startTimes[i+1]) && (endTimes[i]==endTimes[i+1])) {
			continue;
		}
		curMilkLength = endTimes[i]-startTimes[i];
		maxLength = ((curMilkLength>maxLength) ? curMilkLength : maxLength); 
		curNoMilk = startTimes[i+1]-endTimes[i];
		maxNoMilk = ((curNoMilk>maxNoMilk) ? curNoMilk : maxNoMilk);
	}
	curMilkLength = endTimes[N-1]-startTimes[N-1];
	maxLength = ((curMilkLength>maxLength) ? curMilkLength : maxLength);

	out << maxLength << " " << maxNoMilk << "\n";
	return 0;
}

///////////////////////////////////////////////////////////
// Purpose: Sorts the arrays by start time (bubblesort)
// Pre: none (arrays allocated)
// Post: sorts arrays
///////////////////////////////////////////////////////////
void sort()
{
	for(int i=0; i<N-1; i++) {
		for(int j=0; j<N-1-i; j++) {
			if(startTimes[j]>startTimes[j+1]) {
				int temp = startTimes[j+1];
				startTimes[j+1] = startTimes[j];
				startTimes[j] = temp;

				temp = endTimes[j+1];
				endTimes[j+1] = endTimes[j];
				endTimes[j] = temp;
			}
		}
	}
}

///////////////////////////////////////////////////////////
// Purpose: Creates duplicates of the start/end time pairs
// Essentially merges, but keeps two copies.
// Pre: int i: index of pair to be merged (with i+1)
// Post: merges the times
///////////////////////////////////////////////////////////
void merge1(int i)
{
	endTimes[i] = endTimes[i+1];
	startTimes[i+1] = startTimes[i];
}

void merge2(int i)
{
	startTimes[i+1] = startTimes[i];
	endTimes[i+1] = endTimes[i];
}