#include <fstream>
#include <iostream>
using namespace std;

int mod(int m, int n);

int main() {
	// your code goes here
	return 0;
}

int mod(int m, int n)
{
	while(m<0) m+=n;
	return m%n;
}