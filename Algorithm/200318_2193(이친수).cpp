#include<iostream>

using namespace std;
#define MAX 91
long long D[MAX][2];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	D[1][0] = 0;
	D[1][1] = 1;

	for (int i = 2;i <= N;i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}
	cout << D[N][0] + D[N][1] << "\n";

	return 0;
}