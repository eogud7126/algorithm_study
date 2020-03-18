#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 1001
int N;
int Dbig[MAX];
int Dsmall[MAX];
int P[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i <= N;i++) cin >> P[i];
	fill_n(Dbig, N + 1, 1);
	fill_n(Dsmall, N + 1, 1);

	for (int i = 2;i <= N;i++) {
		for (int j = 1;j < i;j++) {
			if (P[i] > P[j]) {
				if (Dbig[i] < Dbig[j] + 1)
					Dbig[i] = Dbig[j] + 1;
			}
		}
	}

	for (int i = N - 1;i >= 2;i--) {
		for (int j = N;j > i;j--) {
			if (P[i] > P[j]) {
				if (Dsmall[i] < Dsmall[j] + 1) {
					Dsmall[i] = Dsmall[j] + 1;
				}
			}

		}
	}
	int answer = 0;
	for (int i = 1;i <= N;i++)
		if (answer < Dbig[i] + Dsmall[i] - 1)
			answer = Dbig[i] + Dsmall[i] - 1;
	cout << answer << "\n";
	return 0;
}