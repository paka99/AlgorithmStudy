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

#define REPEAT(nn) for(int ii = 0; ii < (nn); ii++)
#define FOR(jj, nn) for(int jj = 0; jj < (nn); (jj)++)
#define FORe(ii, nn) for(int ii = 1; ii <= nn; ii++)
#define SIZE(a) ((int)(a).size())
#define ALL(a) (a).begin(),(a).end()

#define IMP (1 << 30)
#define NOP (-1)

int T;
string result;

int color[6];
int tot;

char colorArr[] = "ROYGBV";

int main(){
	cin >> T;
	ofstream ofs("ans2.txt", ios::trunc);
	char buffer[5000];
	//string buffer;

	FOR(t, T){
		result.clear();

		cin >> tot;

		int max1 = 0, max2 = 0;
		int maxCol1 = -1, maxCol2 = -1;
		int third;

		FOR(i, 6)	{
			cin >> color[i];
			if (color[i] > max1){
				max2 = max1;
				maxCol2 = maxCol1;
				max1 = color[i];
				maxCol1 = i;
			}

			else if (color[i] > max2){
				max2 = color[i];
				maxCol2 = i;
			}
		}

		third = ((maxCol1 + maxCol2) * 2) % 6;
		int diff = max1 - max2;
		color[third] -= diff;
		color[maxCol1] -= diff;

		if (color[third] < 0){
			sprintf(buffer, "Case #%d: IMPOSSIBLE", t + 1);
			cout << buffer << endl;
			ofs << buffer << endl;
			continue;
		}

		REPEAT(diff){
			result += colorArr[maxCol1];
			result += colorArr[third];
		}

		diff = color[maxCol2] - color[third];
		color[maxCol1] -= diff;
		color[maxCol2] -= diff;

		if (color[third] < 0){
			sprintf(buffer, "Case #%d: IMPOSSIBLE", t + 1);
			cout << buffer << endl;
			ofs << buffer << endl;
			continue;
		}

		REPEAT(diff){
			result += colorArr[maxCol1];
			result += colorArr[maxCol2];
		}

		REPEAT(color[maxCol2]){
			result += colorArr[maxCol1];
			result += colorArr[maxCol2];
			result += colorArr[third];
		}


		sprintf(buffer, "Case #%d: %s", t + 1, result.c_str());
		cout << buffer << endl;
		ofs << buffer << endl;
	}

	return 0;
}
