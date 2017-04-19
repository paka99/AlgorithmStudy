#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;


void conv(int a, char *dst){
	int idx = 0;
	int ta = a;

	while (a > 0){
		idx++;
		a /= 10;
	}
	idx--;

	while (ta > 0){
		dst[idx--] = (ta % 10) + '0';
		ta /= 10;
	}
}

class RepeatNumberCompare {
public:
	string compare(int x1, int k1, int x2, int k2) {
		string v1;
		string v2;

		for (int k = k1; k > 0; k--){
			char buf[100] = { 0 };
			conv(x1, buf);
			v1 += string(buf);
		}

		for (int k = k2; k > 0; k--){
			char buf[100] = { 0 };
			conv(x2, buf);
			v2 += string(buf);
		}

		if (v1.size() > v2.size())	return string("Greater");
		if (v1.size() < v2.size())	return string("Less");

		int len = v1.size();

		for (int i = 0; i < len; i--){
			if (v1[i] > v2[i])	return string("Greater");
			if (v1[i] <	v2[i])	return string("Less");
		}

		return string("Equal");
	}
};

int main(void)
{

	return 0;
}