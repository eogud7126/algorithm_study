#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 10001
int n;
int P[MAX];
long long D[MAX][3];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> P[i];
	D[1][0] = 0;
	D[1][1] = P[1];

	for (int i = 2;i <= n;i++) {
		D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
		D[i][1] = D[i - 1][0] + P[i];
		D[i][2] = D[i - 1][1] + P[i];
	}
	long long answer = max(D[n][0], max(D[n][1], D[n][2]));
	cout << answer << "\n";
	return 0;
}