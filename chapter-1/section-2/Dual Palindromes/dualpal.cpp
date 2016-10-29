/*
ID: rahul.y1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


/* functions */

// returns true if x is a palindrome, false otherwise
bool isPalindrome(string x, int start, int end);
// returns N converted to base b
string convert(int b, int N);
// returns a^b
int power(int base, int exponent);
char intToChar(int k);
int main()
{
	ifstream in("dualpal.in");
	if(!in) {
		cout << "couldn't dualpal.in";
	}

	ofstream out("dualpal.out");
	if(!out) {
		cout << "couldn't dualpal.out";
	}

	int N;
	int S;
	in >> N;
	in.ignore(1,' ');
	in >> S;
	in.close();

	int i=S+1;
	int numFound=0;
	while(numFound<N) {
		int numPalindrome=0;
		for(int j=2; j<=10; j++) {
			string numString = convert(j,i);
			if(isPalindrome(numString, 0, numString.size()-1))
				numPalindrome++;
		}
		if(numPalindrome>=2) {
			out << i << "\n";
			numFound++;
		}
		i++;
	}
	out.close();

	return 0;
}
bool isPalindrome(string x, int start, int end)
{
	if((end-start)<1) return true;

	if(x[start]==x[end]) return isPalindrome(x, start+1, end-1);
	else return false;
}
//int power(int a, int b)
//{
//	int result=1;
//	for(int i=0; i<b; i++)
//		result*=a;
//
//	return result;
//}
//
//int convert(int n, int b)
//{
//	int i=0;
//	while(power(b, i)<n)
//		i++;
//
//	int answer=0;
//	for(int j=i-1; j>=0; j++) {
//		answer=(10*answer)+(n/power(b,j));
//		n-=(n/power(b,j));
//	}
//
//	return answer;
//}
string convert(int b, int N)
{
	string answer="";
	int i=0;
	bool repeat=true;
	int maxIndex;

	while(repeat) {
		if(power(b,i)<=N) {
			repeat = true;
		}
		else {
			repeat = false;
		}
		i++;
	}

	maxIndex = i-2;

	int j=maxIndex;
	while(N>=0 && j>=0) {
		int k = N/(power(b, j));
		answer.push_back(intToChar(k));
		N-=(k*power(b, j));
		j--;
	}

	return answer;
}
int power(int base, int exponent)
{
	int ans=1;

	for(int i=0; i<exponent; i++) {
		ans *= base;
	}
	return ans;
}
char intToChar(int k)
{
	switch(k) {
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	case 10:
		return 'A';
		break;
	case 11:
		return 'B';
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return 'D';
		break;
	case 14:
		return 'E';
		break;
	case 15:
		return 'F';
		break;
	case 16:
		return 'G';
		break;
	case 17:
		return 'H';
		break;
	case 18:
		return 'I';
		break;
	case 19:
		return 'J';
		break;
	}
}