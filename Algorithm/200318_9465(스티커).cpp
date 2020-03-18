#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 100001

long long D[2][MAX];
int P[2][MAX];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(D, 0, sizeof(D));
		memset(P, 0, sizeof(P));
		int n;
		cin >> n;
		for (int i = 0;i < 2;i++) {
			for (int j = 1;j <= n;j++) {
				cin >> P[i][j];
			}
		}
		D[0][1] = P[0][1];
		D[1][1] = P[1][1];

		for (int i = 2;i <= n;i++) {
			D[0][i] = max(max(D[1][i - 1] + P[0][i], D[0][i - 2] + P[0][i]), D[1][i - 2] + P[0][i]);
			D[1][i] = max(max(D[0][i - 1] + P[1][i], D[1][i - 2] + P[1][i]), D[0][i - 2] + P[1][i]);
		}
		long long answer = max(D[0][n], D[1][n]);
		cout << answer << "\n";
	}

	return 0;
}