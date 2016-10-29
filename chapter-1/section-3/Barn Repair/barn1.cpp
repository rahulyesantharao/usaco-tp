/*
ID: rahul.y1
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

//struct board {
//	int start;
//	int end;
//};

int main()
{
	// declarations
	ifstream in("barn1.in");
	if(!in) {
		cout << "Couldn't open barn1.in";
		return 1;
	}
	ofstream out("barn1.out");
	if(!out) {
		cout << "Couldn't create barn1.out";
		return 1;
	}

	int M;
	int S;
	int C;
	bool *stalls;

	// input
	in >> M;
	in.ignore(1,' ');
	in >> S;
	in.ignore(1,' ');
	in >> C;
	
	// debug
	cout << M << " " << C << " " << S << "\n";
	// debug
	
	stalls = new bool[S];
	
	for(int i=0; i<S; i++) {
		stalls[i] = false;
	}
	
	for(int i=0; i<C; i++) {
		in.ignore(1, '\n');
		int stall;
		in >> stall;
		stalls[stall-1] = true;
	}
	in.close();

	// debug
	for(int i=0; i<S; i++) {
		if(stalls[i]) cout << 1;
		else cout << 0;
	}
	cout << "\n";
	// debug

	// find first true and last true
	int firstTrue=0;
	int lastTrue=S-1;
	while(!stalls[firstTrue]) firstTrue++;
	while(!stalls[lastTrue]) lastTrue--;
	
	// debug
	cout << firstTrue;
	cout << " " << lastTrue << "\n";
	// debug
	
	bool *coveredByBoards;
	coveredByBoards = new bool[S];

	for(int i=0; i<S; i++) {
		coveredByBoards[i]=false;
	}
	for(int i=firstTrue; i<=lastTrue; i++) {
		coveredByBoards[i] = true;
	}
	
		// debug
		for(int i=0; i<S; i++) {
			if(coveredByBoards[i]) cout << 1;
			else cout << 0;
		}
		cout << "\n";
		// debug

	int curStart;
	int curEnd;
	int maxStart;
	int maxEnd;
	for(int j=1; j<M; j++) {
		curStart=firstTrue;
		curEnd=firstTrue;
		maxStart=0;
		maxEnd=0;
		for(int i=firstTrue; i<=lastTrue; i++) {
			if(coveredByBoards[i] && !stalls[i]) {
				curEnd++;
			}
			else {
				if((curEnd-curStart)>(maxEnd-maxStart)) {
					maxStart = curStart;
					maxEnd = curEnd;
				}
				curStart = i+1;
				curEnd = curStart;
			}
		}
		for(int i=maxStart; i<maxEnd; i++) {
			coveredByBoards[i]=false;
		}
		
		// debug
		for(int i=0; i<S; i++) {
			if(coveredByBoards[i]) cout << 1;
			else cout << 0;
		}
		cout << "\n";
		// debug
	}

	int numCovered=0;
	for(int i=0; i<S; i++) {
		if(coveredByBoards[i]) numCovered++;
	}
	out << numCovered << "\n";
	out.close();
	// Greedily start with one board and for each step, remove the largest, contiguous, empty section
	//board *boards;
	//boards = new board[M];
	//boards[0].start = firstTrue;
	//boards[0].end = lastTrue;

	//for(int i=1; i<M; i++) {
	//	int maxBoardNum=0;
	//	int maxStart=0;
	//	int maxEnd=0;

	//	// find longest contiguous nonoccupied covered section.
	//	for(int j=0; j<i; j++) {
	//		int curMax = 0;
	//		int maxCurStart;
	//		int maxCurEnd;
	//		int curLen=0;
	//		int curStart;
	//		int curEnd;
	//		for(int k=boards[j].start; k<=boards[j].end; k++) {
	//			if(stalls[j]) {
	//				curEnd = k-1;
	//				if(curMax<curLen) {
	//					curMax=curLen;
	//					maxCurStart = curStart;
	//					maxCurEnd = curEnd;
	//				}
	//				curStart = k+1;
	//			}
	//			else {
	//				curLen++;
	//			}
	//		}
	//		if(curMax>(maxEnd-maxStart+1)) {
	//			maxBoardNum = j;
	//			maxStart = maxCurStart;
	//			maxEnd = maxCurEnd;
	//		}
	//	}
	//	boards[i].end = boards[maxBoardNum].end;
	//	boards[maxBoardNum].end = maxStart-1;
	//	boards[i].start = maxEnd+1;
	//}


	//for(int i=0; i<M; i++) {
	//	cout << boards[i].start << " " << boards[i].end << "\n";
	//}

	return 0;
}