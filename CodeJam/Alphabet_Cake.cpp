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
int R, C;

char initial[30][30];

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		cin >> R >> C;

		for (int r = 0; r < R; r++)
			cin >> initial[r];


		for (int r = 0; r < R; r++){
			char tmp = '?';

			for (int c = 0; c < C; c++){
				if (initial[r][c] != '?')
					tmp = initial[r][c];

				if (initial[r][c] == '?')
					initial[r][c] = tmp;
			}
			tmp = '?';

			for (int c = C - 1; c >= 0; c--){

				if (initial[r][c] != '?')
					tmp = initial[r][c];


				if (initial[r][c] == '?')
					initial[r][c] = tmp;
			}
		}


		for (int c = 0; c < C; c++){
			char tmp = '?';

			for (int r = 0; r < R; r++){
				if (initial[r][c] != '?')
					tmp = initial[r][c];

				if (initial[r][c] == '?')
					initial[r][c] = tmp;
			}
			tmp = '?';

			for (int r = R - 1; r >= 0; r--){

				if (initial[r][c] != '?')
					tmp = initial[r][c];


				if (initial[r][c] == '?')
					initial[r][c] = tmp;
			}
		}



		printf("Case #%d:\n", t);
		for (int r = 0; r < R; r++){
			cout << initial[r] << endl;
		}
	}



	return 0;
}