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
map < pair<int, int>, bool> guess;
int K, G;
int score;
int resNumerator;
int resDenominator;
int visitCnt;

int gcd(int a, int b){
	while (a*b != 0){
		if (a < b)	b %= a;
		else	a %= b;
	}

	return a == 0 ? b : a;
}

void recur(int root) {
	visitCnt++;
	if (score >= K)	resNumerator++;

	for (int subTreeRoot : childList[root])	{
		if (guess[make_pair(root, subTreeRoot)])	score--;
		if (guess[make_pair(subTreeRoot, root)])	score++;
		recur(subTreeRoot);
		if (guess[make_pair(root, subTreeRoot)])	score++;
		if (guess[make_pair(subTreeRoot, root)])	score--;
	}
}

int main(){
	cin >> T;

	for (int t = 0; t < T; t++){

		cin >> N;

		resNumerator = 0;
		resDenominator = N;

		for (int i = 1; i < N; i++){
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			connection[n1].push_back(n2);
			connection[n2].push_back(n1);
		}

		cin >> G >> K;
		for (int g = 0; g < G; g++){
			int par, child;
			scanf("%d %d", &par, &child);
			guess[make_pair(par, child)] = true;
		}

		bool visit[100000 + 5];
		for (int j = 1; j <= N; j++)	visit[j] = false;

		score = 0;
		queue <int> edgeQ;
		edgeQ.push(1);

		while (!edgeQ.empty()){
			int cur = edgeQ.front();
			edgeQ.pop();
			visit[cur] = true;

			for (int child : connection[cur])	if (!visit[child]){
				childList[cur].push_back(child);
				if (guess[make_pair(cur, child)]){
					score++;
				}
				edgeQ.push(child);
			}
		}
		visitCnt = 0;
		recur(1);

		int D = gcd(resNumerator, resDenominator);
		cout << resNumerator / D << "/" << resDenominator / D << endl;

		for (int i = 1; i <= N; i++) {
			connection[i].clear();
			childList[i].clear();
		}
		guess.clear();
	}

	return 0;
}