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

int T;
int N, K;
double result;
ull intRes;

struct PanCake{
	ll radius;
	ll height;
};

vector <PanCake> pancake;

bool compH(PanCake a, PanCake b){
	if ((a.height*a.radius) > (b.height*b.radius))	return true;
	if ((a.height*a.radius) == (b.height*b.radius) && a.radius > b.radius)	return true;
	return false;
}

const double pi = 3.14159265358979323846264;

int main(){
	cin >> T;
	ofstream ofs("ans2.txt", ios::trunc);
	char buffer[200];

	FOR(t, T){
		result = 0.0;
		intRes = 0;

		cin >> N >> K;
		pancake.resize(N);

		ll maxRadius = 0;
		int maxIndex = -1;

		FOR(n, N){
			cin >> pancake[n].radius >> pancake[n].height;
		}
		::sort(pancake.begin(), pancake.end(), compH);

		ull tmpRes = 0;
		FOR(n, N){
			maxRadius = pancake[n].radius;
			tmpRes = maxRadius*maxRadius;
			tmpRes += maxRadius * pancake[n].height * 2;
			int choice = 1;

			FOR(i, N){
				if (choice == K)	break;

				if (pancake[i].radius <= maxRadius && i != n){
					tmpRes += pancake[i].radius * 2 * pancake[i].height;
					choice++;
				}
			}
			if (intRes < tmpRes)	intRes = tmpRes;
		}

		result = intRes * pi;

		sprintf(buffer, "Case #%d: %.6f", t + 1, result);
		cout << buffer << endl;
		ofs << buffer << endl;

		pancake.clear();
	}

	return 0;
}