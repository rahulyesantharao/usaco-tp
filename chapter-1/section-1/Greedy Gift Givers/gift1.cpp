/*
ID: rahul.y1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int NP;
string people[10];	
int amtMoney[10];
int initMoney[10];

int main()
{
	ifstream in("gift1.in");
	if(!in) {
		cout << "Cannot open gift1.in";
		return 1;
	}
	ofstream out("gift1.out");
	if(!out) {
		cout << "Cannot open gift1.out";
		return 1;
	}

	for(int i=0; i<10; i++) {
		amtMoney[i] = 0;
		initMoney[i] = 0;
	}

	in >> NP;
	in.ignore(1, '\n');
	for(int i=0; i<NP; i++) {
		getline(in, people[i], '\n');
	}

	/*for(int i=0; i<NP; i++) {
		cout << people[i] << "\n";
	}*/

	for(int i=0; i<NP; i++) {
		string temp;
		int loc;
		int numPeople;
		int money;
		bool repeat=true;

		// gets the name of person
		getline(in, temp, '\n');
	//	cout << temp << '\n';

		// finds index of person
		for(int j=0; (j<NP) && repeat; j++) {
			if (!(people[j].compare(temp))) {
				loc = j;
				repeat = false;
			}
		}
	//	cout << loc << '\n';

		in >> money;
	//	cout << money << '\n';
		amtMoney[loc]+=money;
		initMoney[loc]+=money;
	//	cout << amtMoney[loc] << '\n';
	//	cout << initMoney[loc] << '\n';
		in.ignore(1, ' ');
		in >> numPeople;
		in.ignore(1, '\n');
	//	cout << numPeople << '\n';
		if(numPeople!=0) {
			amtMoney[loc]-= (numPeople)*(money/numPeople);
		}
	//	cout << amtMoney[loc] << '\n';

		for(int j=0; j<numPeople; j++) {
			string person;
			int location;
			bool rep=true;

			// gets name of next person
			getline(in, person, '\n');
		//	cout << person << '\n';
			// gets index of next person
			for(int k=0; (k<NP) && rep; k++) {
				if (!(people[k].compare(person))) {
					location = k;
					rep = false;
				}
			}
		//	cout << location << '\n';
			amtMoney[location]+=(money/numPeople);
		//	cout << amtMoney[location] << '\n';
		}
	}

	for(int a=0; a<NP; a++) {
		out << people[a] << " " << (amtMoney[a]-initMoney[a]) << "\n";
	}


	in.close();
	return 0;
}
