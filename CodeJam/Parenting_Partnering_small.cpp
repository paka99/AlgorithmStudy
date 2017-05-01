#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define REAT(nn) for(int ii = 0; ii < (nn); ii++)
#define FOR(jj, nn) for(int jj = 0; jj < (nn); (jj)++)
#define FORe(ii, nn) for(int ii = 1; ii <= nn; ii++)
#define SIZE(a) ((int)(a).size())
#define ALL(a) (a).begin(),(a).end()

#define IMP (1 << 30)
#define NOP (-1)

struct Acitivity{
	int start;
	int end;
};

int T;
int Ac, Aj;
int result;
vector <Acitivity> cameron;
vector <Acitivity> james;

class compObj{
public:
	bool operator() (Acitivity a, Acitivity b){
		return a.start < b.start ? true : false;
	}
};

bool comp(Acitivity a, Acitivity b){
	return a.start < b.start ? true : false;
}

int main(){
	cin >> T;
	ofstream ofs("ans.txt", ios::trunc);
	char buffer[200];

	FOR(t, T){
		result = 0;
		cin >> Ac >> Aj;

		cameron.resize(Ac);
		james.resize(Aj);

		FOR(i, Ac)	cin >> cameron[i].start >> cameron[i].end;
		FOR(i, Aj)	cin >> james[i].start >> james[i].end;

		::sort(james.begin(), james.end(), compObj());
		::sort(cameron.begin(), cameron.end(), compObj());

		if (Ac == 1 && Aj == 1){
			result = 2;
		}

		else if (Ac == 0){
			if (Aj == 1)	result = 2;
			else{
				if (james[1].start - james[0].end >= 720 ||
					james[0].start - james[1].end + 1440 >= 720)
					result = 2;
				else	result = 4;
			}
		}

		else if (Aj == 0){
			if (Ac == 1)	result = 2;
			else{
				if (cameron[1].start - cameron[0].end >= 720 ||
					cameron[0].start - cameron[1].end + 1440 >= 720)
					result = 2;
				else	result = 4;
			}
		}

		printf("Case #%d: %d\n", t + 1, result);
		sprintf(buffer, "Case #%d: %d", t + 1, result);
		ofs << buffer << endl;
	}

	return 0;
}