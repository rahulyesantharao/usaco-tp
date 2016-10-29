/*
PROB: pprime
ID: rahul.y1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int A, B;
bool thePrimes[10001];
// open output
ofstream out("pprime.out");
bool isPrime(int num)
{
	int i=2;
	while(i<=sqrt(num)) {
		if(thePrimes[i] && num%i==0) return false;
	}
	return true;
}

int intLength(int num)
{
	int ans=0;
	while(num>0) {
		num/=10;
		ans++;
	}
	return ans;
}

void genLen(int len, int num, int pos)
{
	if(pos==len) { // done
		if(isPrime(num) && num>=A && num<=B ) out << num <<"\n";
		return;
	}
	
	if(pos==0) {
		for(int i=1; i<=9; i++) {
			genLen(len, num+i*(pow(10,2*len-2)+1), pos+1);
		}
	} else {
		for(int i=0; i<=9; i++) {
			genLen(len, num+i*(pow(10, 2*len-2-pos)+pow(10, pos)), pos+1);
		}
	}
}



int main()
{
	ifstream in("pprime.in");
	in >> A >> B;
	in.close();

	// generate the primes 1->10000
	thePrimes[2]=true;
	for(int i=3; i<=10000; i++) {
		thePrimes[i]=isPrime(i);
	}
	
	// get start and end lengths
	int startLen=intLength(A);
	if(startLen%2==0) startLen++;
	int endLen=intLength(B);
	if(endLen%2==0) endLen--;
	
	// is 11 included?
	bool includesEleven=false;
	if(11>=A && 11<=B) includesEleven=true;
	
	// solve
	for(int i=startLen; i<=endLen; i+=2) {
		if(i==3 && includesEleven) out << 11 << "\n";
		genLen((i+1)/2, 0, 0);
	}
	
	out.close();
	

	return 0;
}