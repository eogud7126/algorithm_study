#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
#define MAX 100001

int D[MAX];
int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	fill_n(D, N + 1, 100001);
	D[0] = 1;
	D[1] = 1;
	for (int i = 2;i <= N;i++) {
		//D[i] = i;
		for (int j = 1;j*j <= i;j++) {
			if (D[i] > D[i - j * j] + 1)
				D[i] = D[i - j * j] + 1;
		}
	}
	cout << D[N] << "\n";
	return 0;
}