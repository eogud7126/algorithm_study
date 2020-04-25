#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
int N, K;
long long D[201][201];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	D[0][0] = 1;
	for (int i = 1;i <= K;i++) {
		for (int j = 0;j <= N;j++) {
			for (int p = 0;p <= j;p++) {
				D[j][i] += D[j - p][i - 1];
				D[j][i] %= 1000000000;
			}
		}
	}

	cout << D[N][K] << endl;
	return 0;
}