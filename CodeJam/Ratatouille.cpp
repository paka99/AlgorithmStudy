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
int R, P;
int require[50];
int package[50][50];

int mink[50][50];
int maxk[50][50];

bool visit[50][50];

int result;
int tmpRes;

void recur(int r, int cnt, int lo, int up){
	if (cnt == P){
		if (result < tmpRes)	result = tmpRes;
		return;
	}

	if (r == R) {
		if (up != -1 && lo <= up)	tmpRes++;
		recur(1, cnt + 1, mink[0][cnt + 1], maxk[0][cnt + 1]);
		if (up != -1 && lo <= up)	tmpRes--;
		return;
	}

	FOR(p, P) {
		if (!visit[r][p]){
			int nextLo = lo < mink[r][p] ? mink[r][p] : lo;
			int nextUp = up > maxk[r][p] ? maxk[r][p] : up;
			visit[r][p] = true;
			recur(r + 1, cnt, nextLo, nextUp);
			visit[r][p] = false;
		}
	}
}

int main(){
	cin >> T;
	ofstream ofs("ans2.txt", ios::trunc);
	char buffer[5000];

	FOR(t, T){
		int maxKit = 0;
		int minKit = (1 << 30);

		result = 0;
		cin >> R >> P;
		FOR(i, R)	cin >> require[i];
		FOR(i, R) FOR(j, P)	cin >> package[i][j];

		FOR(i, R)	::sort(package[i], package[i] + P);

		FOR(i, R) FOR(j, P){
			mink[i][j] = (package[i][j] * 10 - 1) / (require[i] * 11) + 1;
			maxk[i][j] = (package[i][j] * 10) / (require[i] * 9);
			if (maxk[i][j] < mink[i][j])
				maxk[i][j] = mink[i][j] = -1;

			if (maxKit < maxk[i][j])	maxKit = maxk[i][j];
			if (mink[i][j] != -1 && minKit > mink[i][j])	minKit = mink[i][j];
		}

		int idxp[50] = { 0 };

		for (int v = minKit; v <= maxKit; v++){
			bool find = true;
			while (1){
				FOR(i, R){
					while (idxp[i] < P && (mink[i][idxp[i]] == -1 || v > maxk[i][idxp[i]]))
						idxp[i]++;

					if (idxp[i] == P || mink[i][idxp[i]] > v){
						find &= false;
					}

					if (mink[i][idxp[i]] <= v && v <= maxk[i][idxp[i]]){
						find &= true;
					}
				}

				if (find){
					FOR(i, R){
						idxp[i]++;
					}
					result++;
				}

				else
					break;
			}
		}

		//recur(1, 0, mink[0][0], maxk[0][0]);
		sprintf(buffer, "Case #%d: %d", t + 1, result);
		cout << buffer << endl;
		ofs << buffer << endl;
	}

	return 0;
}