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
#define NOP (-1)

int T;
ll N;
int len;


bool isTidyNum(ll n){
	int last = (n % 10);
	n /= 10;

	while (n > 0){
		if (last < (n % 10))	return false;
		last = (n % 10);
		n /= 10;
	}
	
	return true;
}

void parsingDigit(){
	int idx = 0;
	ll n = N;

	while (n > 0){
		n /= 10;
		idx++;
	}

	len = idx;
}

ll findTidyNum(){
	int idx = 0;
	ll n = N;
	ll mask1 = 1;
	ll mask2 = 10;

	while (idx < len - 1){
		int lW = (n / mask1) % 10;
		int mW = (n / mask2) % 10;

		if (lW == 0 || mW > lW){
			n -= (n % mask2) + 1;
			mask1 = 1;
			mask2 = 10;
			idx = 0;
			continue;
		}

		mask1 *= 10;
		mask2 *= 10;
		idx++;
	}

	return n;
}

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		cin >> N;
		parsingDigit();
		ll result = findTidyNum();




		printf("Case #%d: %lld\n", t, result);	
	}



	return 0;
}