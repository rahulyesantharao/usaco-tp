/*
PROB: pprime
ID: rahul.y1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int a,b;
bool primes[10000];
int maxPrime;

int lengthOfNum(int n)
{
	int length=0;
	while(n>0) {
		n/=10;
		length++;
	}
	return length;
}

bool isPrime(int n)
{
	int maxPrimeForN = floor(sqrt(n+0.0));
	int i=2;
	while(i<=maxPrimeForN) {
		if(primes[i] && n%i==0) return false;
		i++;
	}
	return true;
}

int main()
{
	ifstream in("pprime.in");
	in >> a >> b;
	in.close();

	// generate primes
	primes[2]=true;
	maxPrime=2;
	for(int i=3; i<=10000; i++) {
		if(isPrime(i)) {
			primes[i]=true;
			maxPrime=i;
		}
	}
	//

	int startLength=lengthOfNum(a);
	if(startLength%2==0) startLength++;
	int endLength=lengthOfNum(b);
	if(endLength%2==0) endLength--;
	bool minPassed=false;
	bool maxFound=false;
	//cout << startLength << " " << endLength << "\n";
	ofstream out("pprime.out");
	for(int length=startLength; length<endLength; length+=2) {
		if(length==1) {
			for(int i=1; i<=9; i+=2) {
				if(!minPassed) {
					if(i>=a) {
						minPassed=true;
						if(isPrime(i)) out << i << "\n";
					}
				} else {
					if(isPrime(i)) out << i << "\n";
				}
			}
		} else if(length==3) {
		//	cout << "In FIRST loop\n";
			if(a<=11) out << 11 <<"\n";
			for(int i=1; i<=9; i+=2) {
				for(int j=0; j<=9; j++) {
					if(!minPassed) {
						if(a<=100*i+10*j+i ) {
							minPassed=true;
							if(isPrime(100*i+10*j+i )) out << 100*i+10*j+i << "\n";
						}
					} else {
						if(isPrime(100*i+10*j+i )) out << 100*i+10*j+i << "\n";
					}
				}
			}
		} else if(length==5) {
			for(int i=1; i<=9; i+=2) {
				for(int j=0; j<=9; j++) {
					for(int k=0; k<=9; k++) {
						if(!minPassed) {
							if(a<=10000*i+1000*j+100*k+10*j+i ) {
								minPassed=true;
								if(isPrime(10000*i+1000*j+100*k+10*j+i )) out << 10000*i+1000*j+100*k+10*j+i << "\n";
							}
						} else {
							if(isPrime(10000*i+1000*j+100*k+10*j+i )) out << 10000*i+1000*j+100*k+10*j+i << "\n";
						}
					}
				}
			}
		} else if(length==7) {
			for(int i=1; i<=9; i+=2) {
				for(int j=0; j<=9; j++) {
					for(int k=0; k<=9; k++) {
						for(int x=0; x<=9; x++) {
							if(!minPassed) {
								if(a<=1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i ) {
									minPassed=true;
									if(isPrime(1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i )) out << 1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i << "\n";
								}
							} else {
								if(isPrime(1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i )) out << 1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i << "\n";
							}
						}
					}
				}
			}
		}

	}
	
	while(!maxFound) {
		if(endLength==1) {
			for(int i=1; i<=9; i+=2) {
				if(!minPassed) {
					if(i>=a) {
						minPassed=true;
						if(isPrime(i)) out << i << "\n";
					}
				} else if(b>=i ) {
						if(isPrime(i)) out << i << "\n";
				}
				else maxFound=true;
				
			}
		} else if(endLength==3) {
			if(a<=11) out << 11 <<"\n";
			for(int i=1; i<=9; i+=2) {
				for(int j=0; j<=9; j++) {
					if(!minPassed) {
						if(a<=100*i+10*j+i ) {
							minPassed=true;
							if(isPrime(100*i+10*j+i )) out << 100*i+10*j+i << "\n";
						}
					} else if(b>=100*i+10*j+i ) {
						if(isPrime(100*i+10*j+i ))out << 100*i+10*j+i << "\n";
					}
					else maxFound=true;
				}
			}
		} else if(endLength==5) {
			for(int i=1; i<=9; i+=2) {
				for(int j=0; j<=9; j++) {
					for(int k=0; k<=9; k++) {
						if(!minPassed) {
							if(a<=10000*i+1000*j+100*k+10*j+i ) {
								minPassed=true;
								if(isPrime(10000*i+1000*j+100*k+10*j+i )) out << 10000*i+1000*j+100*k+10*j+i << "\n";
							}
						} else if(b>=10000*i+1000*j+100*k+10*j+i) {
							if(isPrime(10000*i+1000*j+100*k+10*j+i )) out << 10000*i+1000*j+100*k+10*j+i << "\n";
						}
						else maxFound=true;
					}
				}
			}
		} else if(endLength==7) {
			for(int i=1; i<=9; i+=2) {
				for(int j=0; j<=9; j++) {
					for(int k=0; k<=9; k++) {
						for(int x=0; x<=9; x++) {
							if(!minPassed) {
								if(a<=1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i ) {
									minPassed=true;
									if(isPrime(1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i )) out << 1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i << "\n";
								}
							} else if(b>=1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i) {
								if(isPrime(1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i )) out << 1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i << "\n";
							}
							else maxFound=true;
						}
					}
				}
			}
		}
	}
	out.close();

	return 0;

}