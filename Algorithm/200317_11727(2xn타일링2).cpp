#include<iostream>

using namespace std;
#define MAX 1001
int D[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	D[0] = 1;
	D[1] = 3;
	int n;
	cin >> n;

	for (int i = 2;i < n;i++) {
		D[i] = D[i - 1] + 2 * D[i - 2];
		D[i] %= 10007;
	}
	cout << D[n - 1];
	return 0;
}