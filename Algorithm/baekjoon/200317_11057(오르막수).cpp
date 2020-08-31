#include<iostream>

using namespace std;
#define MAX 1001
int D[MAX][11];

long long allplus(int N, int L) {
	long long sum = 0;
	for (int k = 0;k <= L;k++) {
		sum += D[N][k];
	}
	return sum % 10007;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0;i <= 9;i++) D[1][i] = 1;

	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			D[i][j] = allplus(i - 1, j);
		}
	}
	long long answer = 0;
	for (int i = 0;i <= 9;i++) {
		answer += D[n][i];
	}
	cout << answer % 10007 << endl;
	return 0;
}