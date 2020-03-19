#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 100001

int N;
int P[MAX];
int D[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> P[i];
		D[i] = P[i];
	}
	long long maxD = -9999999;
	for (int i = 2;i <= N;i++) {
		D[i] = max(D[i - 1] + P[i], P[i]);
	}
	for(int i=1;i<=N;i++) 
		if (maxD < D[i]) {
			maxD = D[i];
		}
	cout << maxD << "\n";
	return 0;
}