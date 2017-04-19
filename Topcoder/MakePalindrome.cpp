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

class MakePalindrome {
public:

	int nCard[30];

	vector <string> constructMinimal(string card) {
		vector <string> ret;
		string center;
		string enenStr;
		string mid;
		bool okayMid = false;

		for (int i = 0; i < 30; i++)	nCard[i] = 0;

		for (char c : card){
			nCard[c - 'a']++;
		}

		for (int i = 0; i < 30; i++){
			if (nCard[i] == 0)	continue;

			if (nCard[i] % 2 == 0){
				char tc = i + 'a';
				for (int j = 0; j < nCard[i] / 2; j++)
					enenStr.push_back(tc);
			}

			if (!okayMid && nCard[i] % 2){
				char tc = i + 'a';
				for (int j = 0; j < nCard[i]; j++)
					mid.push_back(tc);

				okayMid = true;
			}

			else if (okayMid && nCard[i] % 2){
				string tmp;
				char tc = i + 'a';
				for (int j = 0; j < nCard[i]; j++)
					tmp.push_back(tc);

				ret.push_back(tmp);
			}
		}

		for (char e : enenStr){
			center.push_back(e);
		}

		for (char e : mid){
			center.push_back(e);
		}

		for (int i = enenStr.size() - 1; i >= 0; i--){
			char e = enenStr[i];
			center.push_back(e);
		}

		ret.push_back(center);

		return ret;
	}
};


int main(void)
{


	return 0;
}