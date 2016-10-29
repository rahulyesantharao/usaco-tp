/*
PROB: wormhole
ID: rahul.y1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

pair<int, int> points[13];
int N, ans;
int partner[13];
int toRight[13];

int point_to_right(int p)
{
	if(p==1000000) return 1000000;
	if(toRight[p]!=0) return toRight[p];
	int ans=0;
	for(int i=1; i<=N; i++)
		if(points[i].second==points[p].second)
			if(points[i].first>points[p].first)
				if(ans==0 || points[ans].first>points[i].first)
					ans=i;

	return toRight[p]=ans;
}
bool check_cycle()
{
	for(int i=1; i<=N; i++) { // i is the starting point
		int pos=i;
		int num=0;
		do {
			pos=point_to_right(partner[pos]);
		} while(!(pos==i||pos==0) && num<2*N+3);
		if(pos!=0) return true;
	}
	return false;
}
void solve(int n)
{
	if(n==N/2+1) { // check cycle
		//for(int i =1; i<=N; i++) cout << partner[i];
		for(int i=0; i<13; i++) toRight[i]=0;
		if(check_cycle()) ans++;
	}

	int toPair; // first unpaired
	for(toPair=1; toPair<=N; toPair++)
		if(partner[toPair]==0) 
			break;
	//cout << toPair << "\n";
	for(int i=toPair+1; i<=N; i++) {
		if(partner[i]==0) { //i not paired: pair, recurse
			partner[i]=toPair; partner[toPair]=i;
			solve(n+1);
			partner[i]=0; partner[toPair]=0;
		}
	}
}
int main()
{
	ifstream in("wormhole.in");
	in >> N;
	for(int i=1; i<=N; i++) {
		int a,b;
		in >> a >> b;
		points[i]=make_pair(a,b);
	}
	in.close();

	solve(1);

	ofstream out("wormhole.out");
	out << ans << "\n";
	out.close();
}