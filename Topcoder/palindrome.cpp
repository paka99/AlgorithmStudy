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
#include <intrin.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define FOR(nn) for(int ii = 0; ii < (nn); ii++)
#define FOR2(jj, nn) for(int jj = 0; jj < (nn); (jj)++)
#define FOR3(aa, nn) for(int ii = (aa); ii < (nn); ii++)
#define FORe(ii, nn) for(int ii = 1; ii <= nn; ii++)
#define SIZE(a) ((int)(a).size())

#define MOD (1000000007)

class PalindromicSubseq2 {
public:
	string myStr;
	ll cnt;

	ll recur(int s, int e, int c){
		if (s < 0 || e >= myStr.size() || s >= c || e <= c)	return 0;

		ll ret = 0;
		int tmpe = e;
		
		while (tmpe > c && myStr[s] != myStr[tmpe]) {
			tmpe--;
		}

		if (tmpe > c && myStr[s] == myStr[tmpe])	ret = 1;
		ret += recur(s + 1, tmpe - 1, c);

		tmpe = e+1;
		while (tmpe < myStr.size() && myStr[s] != myStr[tmpe]) {
			tmpe++;
		}

		if (tmpe < myStr.size() && myStr[s] == myStr[tmpe])	ret++;
		ret += recur(s + 1, tmpe + 1, c);
		
		return ret;
	}


	int solve(string S) {
		myStr = S;
		ll result = 0;
		ll D[3000] = {};
		D[0] = 1;

		for (ui i = 1; i < S.size(); i++) {
			ll tmpRet = 1;
			//int s = 0;	int e = S.size() - 1;
			//while (s < i) {
			//	tmpRet += recur(s, e, i);
			//	s++;
			//}

			for (int s = 0; s < i; s++){
				for (int e = S.size() - 1; e > i; e--){
					if (S[s] == S[e])	tmpRet++;
				}
			}

			
			D[i] = tmpRet;
		}

		for (ll i = 0; i < S.size(); i++) {
			ll tmp = (i + 1) * D[i];
			tmp %= MOD;
			result += tmp;
		}

		return (int)result;
	}
};

int main(void)
{
	//string aa("axbcba");
	//PalindromicSubseq2 t;
	//t.solve(aa);


	return 0;
}