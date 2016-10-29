/*
ID: rahul.y1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("ride.in.txt");
	if(!in) {
		cout << "Cannot open file\n";
		return 1;
	}
	ofstream out("ride.out");
	if(!out) {
		cout << "Cannot open file\n";
		return 1;
	}


	char comet[7];
	char group[7];
	int cometInt=1;
	int groupInt=1;

	in.getline(comet, 7);
	in.getline(group, 7);

//	cout << comet << "\n" << group << "\n";

	for(int i=0; comet[i]; i++) {
//		cout << (((int)comet[i])-64) << " ";
		cometInt *= (((int)comet[i])-64) ;
	}
	cout << "\n";
	for(int i=0; group[i]; i++) {
//		cout << (((int)group[i])-64) << " ";
		groupInt *= (((int) group[i])-64);
	}

//	cout << "\n" << cometInt << "\n" << groupInt;

	if((cometInt-groupInt)%47==0) out << "GO\n";
	else out << "STAY\n";

	in.close();
	out.close();

	return 0;
}
