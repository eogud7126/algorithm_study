#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 1001
int N;
int D[MAX];
int P[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i <= N;i++) cin >> P[i];
	fill_n(D, N + 1, 1);

	for (int i = 2;i <= N;i++) {
		for (int j = 1;j < i;j++) {
			if (P[i] < P[j])
				if (D[i] < D[j] + 1)
					D[i] = D[j] + 1;
		}
	}
	cout << *max_element(D, D + N + 1)<<"\n";
	return 0;
}