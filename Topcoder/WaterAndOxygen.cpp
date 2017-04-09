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