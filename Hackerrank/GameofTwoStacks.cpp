//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

int main(){
	int g;
	cin >> g;
	for (int a0 = 0; a0 < g; a0++){
		int n;
		int m;
		int x;
		cin >> n >> m >> x;
		vector<int> a(n);
		for (int a_i = 0; a_i < n; a_i++){
			cin >> a[a_i];
		}
		vector<int> b(m);
		for (int b_i = 0; b_i < m; b_i++){
			cin >> b[b_i];
		}
		// your code goes here
		vector <ll> sumA(n + 1);
		ll sum = 0;
		sumA[0] = sum;
		for (int a_i = 1; a_i <= n; a_i++){
			sum += a[a_i - 1];
			sumA[a_i] = sum;
		}

		vector<ll> sumB(m + 1);
		sum = 0;
		sumB[0] = sum;
		for (int b_i = 1; b_i <= m; b_i++){
			sum += b[b_i - 1];
			sumB[b_i] = sum;
		}

		int ret = 0;
		for (int cntA = 0; cntA <= n; cntA++){
			if (sumA[cntA] <= x && ret < cntA)   ret = cntA;
			else if (x < sumA[cntA]) break;

			ll remain = x - sumA[cntA];
			int s = 0, e = m;
			int midB;
			while (s <= e){
				midB = (s + e) / 2;

				if (sumB[midB] <= remain){
					if (ret < cntA + midB)   ret = cntA + midB;
					s = midB + 1;
				}
				else
					e = midB - 1;
			}

		}

		cout << ret << endl;

	}
	return 0;
}
