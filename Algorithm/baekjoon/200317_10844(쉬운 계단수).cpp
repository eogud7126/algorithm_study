#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 101
int N;
long long D[MAX][10] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1;i <= 9;i++) D[1][i] = 1;
	
	int N;
	cin >> N;

	for (int i = 2;i <= N;i++) {
		for (int j = 0;j <= 9;j++) {			
			if (j != 0)
				D[i][j] += D[i - 1][j - 1];
			if (j != 9)
				D[i][j] += D[i - 1][j + 1];
			D[i][j] %= 1000000000;
		}
	}
	long long sum = 0;
	for (int i = 0;i <= 9;i++) sum += D[N][i];
	cout << sum % 1000000000<<"\n";

	return 0;
}