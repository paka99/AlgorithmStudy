//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll strToInt(string a){
	if (a.size() > 1 && a[0] == '0')    return -1;

	int index = 0;
	ll ret = a[index] - '0';

	while (index < a.size() - 1){
		ret *= 10;
		index++;
		ret += a[index] - '0';
	}

	return ret;
}

int numDigit(ll num){
	int ret = 1;
	num /= 10;

	while (num){
		ret++;
		num /= 10;
	}

	return ret;
}

int main(){
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++){
		string s;
		cin >> s;

		// your code goes here
		int len = s.length();
		bool find = false;

		for (int i = 1; !find && i <= len / 2; i++){
			int start = 0;
			int digit = i;
			string tmp(s.begin() + start, s.begin() + start + i);
			ll num = strToInt(tmp);
			if (num == -1)   continue;

			while (1){
				if (start + digit == len){
					cout << "YES " << strToInt(string(s.begin(), s.begin() + i)) << endl;
					find = true;
					break;
				}
				start += digit;
				if (numDigit(num + 1) > digit)  digit++;

				if (start + digit > len)    break;
				string nextStr(s.begin() + start, s.begin() + start + digit);

				ll next = strToInt(nextStr);
				if (next == -1)  break;

				if ((next - num) != 1)    break;

				num = next;
			}
		}
		if (!find)   cout << "NO" << endl;
	}
	return 0;
}
