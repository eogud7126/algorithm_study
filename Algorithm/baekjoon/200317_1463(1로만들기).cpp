#include<iostream>

using namespace std;
#define MAX 1000001
int D[MAX];

int makeOne(int n) {
	if (n == 1) return 0;
	if (D[n] > 0) return D[n];

	D[n] = makeOne(n-1) + 1;
	if (n % 2 == 0) {
		int tmp = makeOne(n / 2) + 1;
		if (D[n] > tmp) D[n] = tmp;
	}
	if (n % 3 == 0) {
		int tmp = makeOne(n / 3) + 1;
		if (D[n] > tmp) D[n] = tmp;
	}

	return D[n];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	cout << makeOne(n) << "\n";

	return 0;
}