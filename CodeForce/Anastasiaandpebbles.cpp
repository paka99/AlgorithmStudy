#include <iostream>

using namespace std;

int N, C;
int result;

int main(){
	cin >> N >> C;

	int consumePocket = 0;
	for (int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;

		consumePocket += (tmp + C - 1) / C;
	}


	result = (consumePocket + 1) / 2;
	cout << result << endl;


	return 0;
}
