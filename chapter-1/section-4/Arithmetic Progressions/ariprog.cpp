/*
PROB: ariprog
ID: rahul.y1
LANG: C++
*/



#include <iostream>
#include <fstream>
//#include <set>
#include <algorithm>
using namespace std;

int M,N;
//set<int> allSums;
bool allSums[125010];
int main()
{
	ifstream in("ariprog.in");
	in >> N >> M;
	in.close();

	// get all possible sums of squares
	for(int i=0; i<=M; i++) {
		for(int j=i; j<=M; j++) {
			//allSums.insert((i*i)+(j*j));
			allSums[((i*i)+(j*j))]=true;
		}
	}

	int maxDiff=(2*M*M)/(N-1);
	bool found=false;
	ofstream out("ariprog.out");
	for(int diff=1; diff<=5000; diff++) {
		//set<int>::iterator it=allSums.begin();
		///while(it!=allSums.end() && (*it+(N-1)*diff)<=2*M*M) {
		int check=0;
		while(check<125001 && check+(N-1)*diff<=2*M*M) {
			if(allSums[check]) {
				int n;
				for(n=1; n<N; n++) {
					//if(allSums.find(*it+(diff)*n)==allSums.end())
					if(!allSums[check+n*diff])
						break;
				}
				if(n==N) {
					found=true;
					out << check << " " << diff << "\n";
				}
			}
			check++;
		}
	}
	if(!found) {
		out << "NONE\n";
	}
	out.close();
	return 0;
}