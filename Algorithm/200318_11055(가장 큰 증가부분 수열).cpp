#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 1001
int N;
long long D[MAX];
int P[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> P[i];
		D[i] = P[i];
	}
	D[1] = P[1];

	for (int i = 2;i <= N;i++) {
		for (int j = 1;j < i;j++) {
			if (P[j] < P[i]) {
				if (D[i] < D[j] + P[i])
					D[i] = D[j] + P[i];
			}
		}
	}
	cout << *max_element(D, D + N + 1) << "\n";
	return 0;
}