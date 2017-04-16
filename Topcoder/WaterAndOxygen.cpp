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


class WaterAndOxygen {
public:
	double maxDays(int remainH20, int remainO2, int costH2O, int costO2) {
		double ret = 0.0;
		ret += min((double)remainH20 / costH2O, (double)remainO2 / costO2);

		double rH2O = remainH20 - ret * costH2O;
		double rO2 = remainO2 - ret * costO2;

		if (rH2O > 0.0){
			ret += rH2O / ((double)costO2 * 2 + costH2O);
		}

		return ret;
	}
};

int main(void)
{

	return 0;
}