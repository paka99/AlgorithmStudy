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

#define NDF (-26)


class AlphabetOrderDiv1{
public:
	string isOrdered(vector <string> words){
		int order[26][26];
		vector <vector <int>> list;
		list.resize(26);
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < 26; j++){
				if (i == j)	order[i][j] = 0;
				else	order[i][j] = NDF;
			}
		}

		for (string str : words){
			for (int i = 1; i < SIZE(str); i++){
				if (order[str[i - 1] - 'a'][str[i] - 'a'] == NDF){
					order[str[i - 1] - 'a'][str[i] - 'a'] = 1;
					order[str[i] - 'a'][str[i - 1] - 'a'] = -1;
					list[str[i] - 'a'].push_back(str[i - 1] - 'a');

					for (int dec : list[str[i - 1] - 'a']){
						if (order[dec][str[i]- 'a'] == -1)
							return "Impossible";

						order[dec][str[i] - 'a'] = 1;
						order[str[i] - 'a'][dec] = -1;
						list[str[i] - 'a'].push_back(dec);
					}
				}

				else if (order[str[i - 1] - 'a'][str[i] - 'a'] == -1){
					return "Impossible";
				}
			}
		}
		return "Possible";
	}
};