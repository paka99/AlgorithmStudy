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

#define IMP (1 << 30)

int T;

string pancakeRow;
int K;
int result;
int len;
int D[1000 + 5];
bool visit[1000 + 5][1000 + 5];

bool isHappyUntil(string a, int until){
	for (int i = 0; i <= until; i++){
		if (a[i] == '+')	continue;
		else if (a[i] == '-')	return false;
	}

	return true;
}


bool isAllhappy(string a){
	//for (int i = 0; i < len; i++){
	//	if (a[i] == '+')	continue;
	//	else if (a[i] == '-')	return false;
	//}
	//return true;
	return isHappyUntil(a, len - 1);
}


void bruteFoce(string cur, int flipedIndex, int numTime){

	if (isAllhappy(cur)){
		if (numTime < result)
			result = numTime;
	}

	//if (isHappyUntil(cur, flipedIndex)){
	//	if (D[flipedIndex] > numTime)	D[flipedIndex] = numTime;
	//	else	return;
	//}

	//if (visit[flipedIndex][numTime])	return;
	//visit[flipedIndex][numTime] = true;


	if (flipedIndex > len - K)	return;

	if (cur[flipedIndex] == '+') {
		bruteFoce(cur, flipedIndex + 1, numTime);
		return;
	}

	//if (cur[flipedIndex] == '+')	return;
	for (int i = flipedIndex; i < flipedIndex + K; i++){
		if (cur[i] == '+')	cur[i] = '-';
		else if (cur[i] == '-')	cur[i] = '+';
	}

	bruteFoce(cur, flipedIndex + 1, numTime+1);
}


int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		result = IMP;
		for (int i = 0; i < 1000 + 5; i++)	{
			for (int j = 0; j < 1000 + 5; j++)	visit[i][j] = false;
				D[i] = IMP;
		}
		cin >> pancakeRow;
		cin >> K;


		len = pancakeRow.length();

		bruteFoce(pancakeRow, 0, 0);


		if (result == IMP)	printf("Case #%d: IMPOSSIBLE\n", t);
		else	printf("Case #%d: %d\n", t, result);
	}



	return 0;
}