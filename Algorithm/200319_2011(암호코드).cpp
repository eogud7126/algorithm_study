#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;
string s;
long long D[5001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	D[0] = 1;
	int n = s.size();
	s = " " + s;

	
	for (int i = 1;i <= n;i++) {
		if (0 < stoi(s.substr(i, 1)) && stoi(s.substr(i, 1)) < 10) {
			D[i] += D[i - 1];
		}

		if (i == 1) continue;
		if (s[i - 1] == '0') continue;
		if (stoi(s.substr(i-1, 2)) >= 10 && stoi(s.substr(i-1, 2)) <= 26)
			D[i] = D[i] + D[i - 2];
		D[i] %= 1000000;
	}
	
	cout << D[n]<<endl;
	return 0;
}