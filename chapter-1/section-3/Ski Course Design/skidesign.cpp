/*
PROB: skidesign
ID: rahul.y1
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int N;
long long hills[1000];

int main()
{
	ifstream in("skidesign.in");
	in >> N;
	for(int i=0; i<N; i++) in >> hills[i];
	in.close();

	int best=1000000000;
	for(int i=0; i<=83; i++) { // i is the bottom height
		long long amt=0;
		for(int j=0; j<N; j++) {
			if(hills[j]<i) amt+=(i-hills[j])*(i-hills[j]);
			else if(hills[j]>i+17) amt+=(hills[j]-i-17)*(hills[j]-i-17);
		}
		if(amt<best) best=amt;
	}

	ofstream out("skidesign.out");
	out << best << "\n";
	out.close();

	return 0;
}