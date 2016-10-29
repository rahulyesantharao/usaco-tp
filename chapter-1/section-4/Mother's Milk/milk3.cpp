/*
PROB: milk3
ID: rahul.y1
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int A,B,C;
int visited[21][21][21];
set<int> possibleC;

void solve(int curA, int curB, int curC)
{
	if(visited[curA][curB][curC]==1) return;

	if(curA==0) {
		possibleC.insert(curC);
	}

	visited[curA][curB][curC]=1;
	// A->B
	if(B-curB>=curA)
		solve(0, curB+curA, curC);
	else 
		solve(curA+curB-B, B, curC);

	// A->C
	if(C-curC>=curA)
		solve(0, curB, curC+curA);
	else 
		solve(curA+curC-C, curB, C);

	// B->A
	if(A-curA>=curB)
		solve(curB+curA, 0, curC);
	else 
		solve(A, curA+curB-A, curC);

	// B->C
	if(C-curC>=curB)
		solve(curA, 0, curB+curC);
	else 
		solve(curA, curB+curC-C, C);

	// C->A
	if(A-curA>=curC)
		solve(curA+curC, curB, 0);
	else
		solve(A, curB, curA+curC-A);

	// C->B
	if(B-curB>=curC)
		solve(curA, curB+curC, 0);
	else
		solve(curA, B, curB+curC-B);

	visited[curA][curB][curC]=0;
}
int main()
{
	ifstream in("milk3.in");
	in >> A >> B >> C;
	in.close();

	solve(0,0,C);
	ofstream out("milk3.out");
	int num=0;
	for(set<int>::iterator it=possibleC.begin(); it!=possibleC.end(); it++) {
		num++;
		if(num==possibleC.size()) {
			out << *it << "\n";
		} else {
			out << *it << " ";
		}
	}
	out.close();
	return 0;
}