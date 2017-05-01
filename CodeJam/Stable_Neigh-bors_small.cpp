#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <ctime>
#include <list>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <intrin.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int T;
string result;
int N;
int numUnicorn[6];
bool isPossible;

enum { red = 2, blue = 3, yellow = 5, violet = 6, orange = 10, green = 15 };

int colorArr[] = { 2, 10, 5, 15, 3, 6 };

bool isEmpty(){
	FOR2(i, 6){
		if (numUnicorn[i] == 0)	continue;
		return false;
	}

	return true;
}

string convertToString(vector <int> tmpResult){
	string ret;

	for (int a : tmpResult){
		switch (a){
		case 2:
			ret.push_back('R');
			break;

		case 3:
			ret.push_back('B');
			break;

		case 5:
			ret.push_back('Y');
			break;

		case 10:
			ret.push_back('O');
			break;

		case 6:
			ret.push_back('V');
			break;

		case 15:
			ret.push_back('G');
			break;
		}
	}

	return ret;
}

int main(){
	cin >> T;
	int maxIdx;

	for (int t = 1; t <= T; t++){
		result.clear();
		isPossible = true;

		int max1 = -1, max2 = -1;
		int maxIdx1 = 0, maxIdx2 = 0;

		cin >> N;
		FOR2(i, 6)	cin >> numUnicorn[i];


		FOR2(i, 6){
			if (numUnicorn[i] > max1)	{
				max2 = max1;
				maxIdx2 = maxIdx1;
				max1 = numUnicorn[i];
				maxIdx1 = i;
			}
			else if (numUnicorn[i] > max2) {
				max2 = numUnicorn[i];
				maxIdx2 = i;
			}
		}

		int thirdIdx = -1;

		if (maxIdx1 + maxIdx2 == 6)	thirdIdx = 0;
		else if (maxIdx1 + maxIdx2 == 2)	thirdIdx = 4;
		else if (maxIdx1 + maxIdx2 == 4)	thirdIdx = 2;


		int d = max1 - max2;
		if (thirdIdx == -1 || d > numUnicorn[thirdIdx]){
			isPossible = false;
			if (!isPossible)	result = string("IMPOSSIBLE");
			printf("Case #%d: %s\n", t, result.c_str());
			continue;
		}

		vector <int> pattern;

		FOR2(i, d){
			pattern.push_back(colorArr[maxIdx1]);
			pattern.push_back(colorArr[thirdIdx]);
		}


		int d2 = numUnicorn[thirdIdx] - d;
		FOR2(i, d2){
			pattern.push_back(colorArr[maxIdx1]);
			pattern.push_back(colorArr[maxIdx2]);
			pattern.push_back(colorArr[thirdIdx]);
		}


		int d3 = max2 - d2;
		FOR2(i, d3){
			pattern.push_back(colorArr[maxIdx1]);
			pattern.push_back(colorArr[maxIdx2]);
		}

		result = convertToString(pattern);

		if (!isPossible)	result = string("IMPOSSIBLE");
		printf("Case #%d: %s\n", t, result.c_str());
	}

	return 0;
}
