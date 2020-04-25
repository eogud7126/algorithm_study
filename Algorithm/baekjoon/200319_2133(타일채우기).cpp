#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
long long D[31];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	D[0] = 1;
	D[2] = 3;
	for (int i = 4;i <= N;i+=2) {
		D[i] = D[i - 2] * 3;
		for (int j = 4;j <= i;j += 2)
			D[i] = D[i] + D[i - j] * 2;
	}
	cout << D[N] << "\n";
	return 0;
}