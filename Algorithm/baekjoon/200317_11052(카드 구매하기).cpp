#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 1001
int N;
int P[MAX];
int D[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1;i <= N;i++) cin >> P[i];
	D[1] = P[1];

	for (int i = 1;i <= N;i++) {
		for(int j=0;j<=i;j++)
			D[i] = max(D[i], D[i - j] + P[j]);
	}

	cout << D[N] << endl;
	return 0;
}