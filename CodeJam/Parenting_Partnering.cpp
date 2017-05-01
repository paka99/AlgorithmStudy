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
	int parent;

	Acitivity(){}
	Acitivity(int s, int e, int p){
		start = s;
		end = e;
		parent = p;
	}
};

struct Schedule{
	int parent;
	int len;

	Schedule(){}
	Schedule(int p, int l)	{
		parent = p;
		len = l;
	}
};

int T;
int Ac, Aj;
int result;

vector <Acitivity> act;
vector <Schedule> g;

class compObj{
public:
	bool operator() (Acitivity a, Acitivity b){
		return a.start < b.start ? true : false;
	}

	bool operator() (Schedule a, Schedule b){
		return a.len < b.len ? true : false;
	}
};

int main(){
	cin >> T;
	ofstream ofs("ans2.txt", ios::trunc);
	char buffer[200];

	FOR(t, T){
		result = 0;
		cin >> Ac >> Aj;

		FOR(i, Ac)	{
			int s, e;
			cin >> s >> e;
			act.push_back(Acitivity(s, e, 1));
		}
		FOR(i, Aj) {
			int s, e;
			cin >> s >> e;
			act.push_back(Acitivity(s, e, 2));
		}

		::sort(ALL(act), compObj());

		int jTime = 0;
		int cTime = 0;

		FOR(i, Ac + Aj){
			if (act[i].parent == 1)
				jTime += act[i].end - act[i].start;
			if (act[i].parent == 2)
				cTime += act[i].end - act[i].start;
		}

		for (int i = 0; i < SIZE(act); i++){
			int next = (i + 1) % SIZE(act);

			if (act[next].parent == act[i].parent){
				g.push_back(Schedule(act[next].parent, (act[next].start - act[i].end + 1440) % 1440));
			}
			else	result++;
		}

		::sort(ALL(g), compObj());

		for (auto a : g){
			if (a.len > 0){
				if (a.parent == 1){
					if (jTime + a.len <= 720){
						jTime = jTime + a.len;
					}

					else	result += 2;
				}

				if (a.parent == 2){
					if (cTime + a.len <= 720){
						cTime = cTime + a.len;
					}

					else	result += 2;
				}
			}
		}

		printf("Case #%d: %d\n", t + 1, result);
		sprintf(buffer, "Case #%d: %d", t + 1, result);
		ofs << buffer << endl;

		g.clear();
		act.clear();
	}

	return 0;
}