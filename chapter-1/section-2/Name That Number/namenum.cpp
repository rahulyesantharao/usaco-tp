/*
ID: rahul.y1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool match(string k, string name);
char convertChar(char c);

int main()
{
	string n;

	// opens files
	ifstream dictionary("dict.txt");
	if(!dictionary) {
		cout << "Could not open dict.txt";
		return 1;
	}
	ifstream in("namenum.in");
	if(!in) {
		cout << "Could not open namenum.in";
		return 1;
	}
	ofstream out("namenum.out");
	if(!out) {
		cout << "Could not open namenum.out";
		return 1;
	}
	
	// gets the given number
	in >> n;		// n cannot hold large enough value
	in.close();


	//cout << n << "\n";
	// gets the number of lines in dictionary
	int numLines=0;
	char temp1[13];
	while(!dictionary.eof()) {
		dictionary.getline(temp1, 13);
		numLines++;
	}
	//cout << numLines << "\n";
	dictionary.clear();
	dictionary.seekg(0);

	// loops through dictionary to find words that match with the number
	string temp;
	bool hasSomething = false;
	for(int i=0; i<numLines; i++) {
		getline(dictionary, temp);
		//cout << temp << "\n";
		bool result = match(n,temp);
		//cout <<result;
		if(result) {
			out << temp << "\n";
			hasSomething = true;
		}
	}
	if(!hasSomething) {
		out << "NONE\n";
	}
	dictionary.close();
	out.close();

	return 0;
}

char convertChar(char c)
{
	switch(c) {
	case 'A':
		return '2';
		break;
	case 'B':
		return '2';
		break;
	case 'C':
		return '2';
		break;
	case 'D':
		return '3';
		break;
	case 'E':
		return '3';
		break;
	case 'F':
		return '3';
		break;
	case 'G':
		return '4';
		break;
	case 'H':
		return '4';
		break;
	case 'I':
		return '4';
		break;
	case 'J':
		return '5';
		break;
	case 'K':
		return '5';
		break;
	case 'L':
		return '5';
		break;
	case 'M':
		return '6';
		break;
	case 'N':
		return '6';
		break;
	case 'O':
		return '6';
		break;
	case 'P':
		return '7';
		break;
	case 'R':
		return '7';
		break;
	case 'S':
		return '7';
		break;
	case 'T':
		return '8';
		break;
	case 'U':
		return '8';
		break;
	case 'V':
		return '8';
		break;
	case 'W':
		return '9';
		break;
	case 'X':
		return '9';
		break;
	case 'Y':
		return '9';
		break;
	}
}

bool match(string k, string name)
{
	string nameNum;
	int len = name.size();
	//cout << k.size() << " " << name.length() << "\n";
	
	if(k.size() != len) {
		return false;
	}

	for(int i=0; i<len; i++) {
		nameNum.push_back(convertChar(name[i]));
	}
	//cout << nameNum << "\n";
	if(k.compare(nameNum)==0) {
			return true;
	}
	return false;
}