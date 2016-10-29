/*
PROB: combo
ID: rahul.y1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> fJohn;
vector<int> master;
int N, ans;

bool close_enough(int a, int b, int c)
{
	if(((abs((a-fJohn[0]))<=2)||(abs((a-fJohn[0]))>=N-2)) && ((abs((b-fJohn[1]))<=2)||(abs((b-fJohn[1]))>=N-2)) && ((abs((c-fJohn[2]))<=2)||(abs((c-fJohn[2]))>=N-2))) return true;
	if(((abs((a-master[0]))<=2)||(abs((a-master[0]))>=N-2)) && ((abs((b-master[1]))<=2)||(abs((b-master[1]))>=N-2)) && ((abs((c-master[2]))<=2)||(abs((c-master[2]))>=N-2))) return true;
	return false;
}

int main()
{
	ifstream in("combo.in");
	in >> N;
	int a,b,c;
	in >> a >> b>> c;
	fJohn.push_back(a-1);
	fJohn.push_back(b-1);
	fJohn.push_back(c-1);
	in >> a >> b >> c;
	master.push_back(a-1);
	master.push_back(b-1);
	master.push_back(c-1);
	in.close();

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			for(int k=0; k<N; k++) {
				if(close_enough(i,j,k)) ans++;
			}
		}
	}


	ofstream out("combo.out");
	out << ans << "\n";
	out.close();

	return 0;
}