//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long int ll;

int T, N;
vector <int> connection[100000 + 5];
vector <int> childList[100000 + 5];
vector < pair <int, int> > guess;
int K, G;

int gcd(int a, int b){
	while (a*b != 0){
		if (a < b)	b %= a;
		else	a %= b;
	}

	if (a == 0)	return b;
	return a;
}

int main(){
	cin >> T;

	for (int t = 0; t < T; t++){
		cin >> N;

		int resNumerator = 0;
		int resDenominator = N;

		for (int i = 1; i < N; i++){
			int n1, n2;
			//cin >> n1 >> n2;
			scanf("%d %d", &n1, &n2);
			connection[n1].push_back(n2);
			connection[n2].push_back(n1);
		}

		cin >> G >> K;
		for (int g = 0; g < G; g++){
			int par, child;
			//cin >> par >> child;
			scanf("%d %d", &par, &child);
			guess.push_back(make_pair(par, child));
		}

		bool visit[100000 + 5];
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				visit[j] = false;
			}

			queue <int> edgeQ;
			edgeQ.push(i);
			visit[i] = true;

			while (!edgeQ.empty()){
				int cur = edgeQ.front();
				edgeQ.pop();
				visit[cur] = true;

				for (int child : connection[cur])	if (!visit[child]){
					childList[cur].push_back(child);
					edgeQ.push(child);
				}
			}

			int score = 0;
			for (int n = 0; n < G; n++){
				int par = guess[n].first;
				int child = guess[n].second;

				for (int c : childList[par])	if (c == child){
					score++;
					break;
				}

				if (score >= K)	{
					resNumerator++;
					break;
				}
			}

			for (int j = 1; j <= N; j++){
				childList[j].clear();
			}
		}

		int D = gcd(resNumerator, resDenominator);
		cout << resNumerator / D << "/" << resDenominator / D << endl;

		for (int i = 1; i <= N; i++)	{
			connection[i].clear();
		}
		guess.clear();

	}

	return 0;
}