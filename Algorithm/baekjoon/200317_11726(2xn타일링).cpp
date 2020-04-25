#include<iostream>

using namespace std;
#define MAX 1001
int D[MAX];

int howMany(int n) {
	if (n == 0 || n == 1) return 1;
	if (D[n] > 0) return D[n]%10007;

	D[n] = howMany(n - 1) + howMany(n - 2);

	return D[n]%10007;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	cout << howMany(n) << "\n";

	return 0;
}