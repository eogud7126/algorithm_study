#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 301

int N;
int P[MAX];
long long D[MAX][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> P[i];

	}
	//0: 연속1계단
	//1: 연속2계단
	D[1][0] = P[1];
	D[1][1] = 0;
	D[2][0] = P[2];
	D[2][1] = P[1] + P[2];
	for (int i = 3;i <= N;i++) {
		D[i][0] = max(D[i - 2][0], D[i - 2][1]) + P[i];
		D[i][1] = D[i - 1][0] + P[i];
	}
	cout << max(D[N][0], D[N][1]) << "\n";
	return 0;
}