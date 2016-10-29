/*
ID: rahul.y1
PROG: friday
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

int N;
int curDay=0;
int mon, tues, wed, thurs, fri, sat, sun;

bool leapyear(int n);
void addDay(int day);
void cycleLeapYear();
void cycleNormYear();
void cycleThirty();
void cycleTOne();
void cycleTweNine();
void cycleTweEight();

int main()
{
	mon=tues=wed=thurs=fri=sat=sun=0;
	ifstream in("friday.in");
	if(!in) {
		cout << "Cannot open file friday.in";
		return 1;
	}
	ofstream out("friday.out");
	if(!out) {
		cout << "Cannot open file friday.out";
		return 1;
	}

	in >> N;
	in.close();

	for(int i=1900; i<1900+N; i++) {
		bool leap_year;
		leap_year = leapyear(i); 

		if(leap_year) {
			cycleLeapYear();
		}
		else {
			cycleNormYear();
		}

	}

	out << sat << " " << sun << " " << mon << " " << tues << " " << wed << " " << thurs << " " << fri << "\n" ; 
	out.close();
	return 0;
}

bool leapyear(int n)
{
	if(n%400==0) {
		return true;
	}
	else if((n%4==0)&&(n%100!=0)) {
		return true;
	}
	return false;
}
void addDay(int day)
{
	switch(day) {
	case 0:
		mon++;
//		cout << "Monday\n";
		break;
	case 1:
		tues++;
//		cout << "Tuesday\n";
		break;
	case 2:
		wed++;
//		cout << "Wednesday\n";
		break;
	case 3:
		thurs++;
//		cout << "Thursday\n";
		break;
	case 4:
		fri++;
//		cout << "Friday\n";
		break;
	case 5:
		sat++;
//		cout << "Saturday\n";
		break;
	case 6:
		sun++;
//		cout << "Sunday\n";
		break;
	}
}
void cycleLeapYear()
{
	cycleTOne();
	cycleTweNine();
	cycleTOne();
	cycleThirty();
	cycleTOne();
	cycleThirty();
	cycleTOne();
	cycleTOne();
	cycleThirty();
	cycleTOne();
	cycleThirty();
	cycleTOne();
}
void cycleNormYear()
{
	cycleTOne();
	cycleTweEight();
	cycleTOne();
	cycleThirty();
	cycleTOne();
	cycleThirty();
	cycleTOne();
	cycleTOne();
	cycleThirty();
	cycleTOne();
	cycleThirty();
	cycleTOne();
}

void cycleThirty()
{
	int k;
	for(k=1; k<=30; k++) {
		if(k==13) {
			addDay(curDay);
		}
		curDay++;
		curDay%=7;
	}
}
void cycleTOne()
{
	int k;
	for(k=1; k<=31; k++) {
		if(k==13) {
			addDay(curDay);
		}
		curDay++;
		curDay%=7;
	}
}
void cycleTweNine()
{
	int k;
	for(k=1; k<=29; k++) {
		if(k==13) {
			addDay(curDay);
		}
		curDay++;
		curDay%=7;
	}
}
void cycleTweEight()
{
	int k;
	for(k=1; k<=28; k++) {
		if(k==13) {
			addDay(curDay);
		}
		curDay++;
		curDay%=7;
	}
}


