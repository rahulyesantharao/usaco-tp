/*
ID: rahul.y1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// convert N base 10 to base b
string convert (int b, int N);
//int minMultLess(int x, int y);
char intToChar(int k);
bool isPalindrome(string k, int start, int end);
int power(int base, int exponent);

int main()
{
	int B;
	ofstream out("palsquare.out");
	if(!out) {
		cout << "Cannot palsquare.out";
		return 1;
	}
	ifstream in("palsquare.in");
	if(!in) {
		cout << "Cannot palsquare.in";
		return 1;
	}

	in >> B;
	in.close();

	for(int i=1; i<=300; i++) {
		string temp = convert(B, i*i);
		//cout << temp.c_str() <<"\n";
		if(isPalindrome(temp,0,temp.size()-1)) {
			out << convert(B, i) << " " << temp << "\n";
		}
	}

	out.close();

	return 0;
}





//int minMultLess(int x, int y)
//{
//	bool repeat = true;
//	int k=0;
//	while(repeat) {
//		if(x*k<y) {
//			repeat = true;
//		}
//		else {
//			repeat = false;
//		}
//		k++;
//	}
//	return (k-1);
//}
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
bool isPalindrome(string k, int start, int end)
{
	//int len = k.size();
	//if(len%2==0) {
	//	for(int i=0; (i<(len)/2); i++) {
	//		if(!(k[i]==k[len-1-i])) return false;
	//	}
	//}
	//else {
	//	for(int i=0; i<(len-1)/2; i++) {
	//		if(!(k[i]==k[len-1-i])) return false;
	//	}
	//}
	//return true;

	if((end-start)<1) return true;
	if(k[start]==k[end]) return isPalindrome(k, start+1, end-1);
	else return false;
}
int power(int base, int exponent)
{
	int ans=1;

	for(int i=0; i<exponent; i++) {
		ans *= base;
	}
	return ans;
}
	
