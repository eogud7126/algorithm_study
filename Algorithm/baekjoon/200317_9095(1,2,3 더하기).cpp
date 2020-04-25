#include<iostream>

using namespace std;
#define MAX 1001
int D[MAX];

int plus123(int n) {
	if (D[n] > 0) return D[n];

	D[n] = plus123(n - 1) + plus123(n - 2) + plus123(n - 3);

	return D[n];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	while (t--) {
		int n;
		cin >> n;
		cout << plus123(n) << "\n";
	}

	return 0;
}