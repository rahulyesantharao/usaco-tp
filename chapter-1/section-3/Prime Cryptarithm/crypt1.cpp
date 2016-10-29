/*
ID: rahul.y1
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int numDigits(int n);
int digAt(int num, int index);
bool isIn(int num);

int N;
int *nums;

int main()
{
	ifstream in("crypt1.in");
	if(!in) {
		cout << "Couldn't open crypt1.in";
		return 1;
	}
	ofstream out("crypt1.out");
	if(!out) {
		cout << "Couldn't open crypt1.out";
		return 1;
	}

	
	in >> N;
	in.ignore(1,'\n');
	nums = new int[N];
	for(int i=0; i<N; i++) {
		in >> nums[i];
		if(i<N-1) in.ignore(1,' ');
	}
	in.close();

	
	// bash through all possibilities
	int numSolutions=0;
	for(int a=0; a<N; a++) {
		for(int b=0; b<N; b++) {
			for(int c=0; c<N; c++) {
				for(int d=0; d<N; d++) {
					for(int e=0; e<N; e++) {
						// a,b,c: 3 digit
						// d,e  : 2 digit
						int threeDigit = 100*nums[a]+10*nums[b]+nums[c];
						int twoDigit = 10*nums[d]+nums[e];
						if((numDigits(twoDigit*threeDigit)==4)&&(numDigits(nums[e]*threeDigit)==3)&&(numDigits(nums[d]*threeDigit)==3)) {
							if((isIn(digAt(twoDigit*threeDigit,0)))&&(isIn(digAt(twoDigit*threeDigit,1)))&&(isIn(digAt(twoDigit*threeDigit,2)))&&(isIn(digAt(twoDigit*threeDigit,3)))&&(isIn(digAt(nums[d]*threeDigit,0)))&&(isIn(digAt(nums[d]*threeDigit,1)))&&(isIn(digAt(nums[d]*threeDigit,2)))&&(isIn(digAt(nums[e]*threeDigit,0)))&&(isIn(digAt(nums[e]*threeDigit,1)))&&(isIn(digAt(nums[e]*threeDigit,2)))) {
								cout << threeDigit << "\n";
								cout << " " << twoDigit << "\n";
								numSolutions++;
							}
						}
					}
				}
			}
		}
	}

	cout << numSolutions;
	out << numSolutions <<"\n";
	out.close();
	return 0;
}

int numDigits(int n)
{
	int num = 0;
	while(n>0) {
		num++;
		n/=10;
	}
	return num;
}
int digAt(int num, int index)
{
	for(int i=0; i<index; i++) {
		num/=10;
	}
	return num%10;
}
bool isIn(int num)
{
	for(int i=0; i<N; i++) {
		if(nums[i]==num) return true;
	}
	return false;
}
