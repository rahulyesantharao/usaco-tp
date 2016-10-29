/*
PROB: numtri
ID: rahul.y1
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int R;
int answers[1000][1000];

int main()
{
	ifstream in("numtri.in");
	in >> R;
	in >> answers[0][0];
	for(int i=1; i<R; i++) {
		for(int j=0; j<i+1; j++) {
			int num;
			in >> num;
			if(j==0) { // first element
				answers[i][j]=answers[i-1][j]+num;
			} else if(j==i) { // last element
				answers[i][j]=answers[i-1][j-1]+num;
			} else { // in the middle
				answers[i][j]=max(answers[i-1][j-1], answers[i-1][j])+num;
			}
		}
	}
	in.close();

	int finalAns=0;
	for(int i=0; i<R; i++) {
		finalAns=max(finalAns, answers[R-1][i]);
	}

	ofstream out("numtri.out");
	out << finalAns<< "\n";
	out.close();
	return 0;
}