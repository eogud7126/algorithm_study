#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
long long D[101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	D[0] = 0, D[1] = 1, D[2] = 1, D[3] = 1, D[4] = 2;
	while (T--) {
		cin >> N;
		for (int i = 5;i <= N;i++) {
			D[i] = D[i - 1] + D[i - 5];
		}
		cout << D[N]<<"\n";
	}
	
	
	return 0;
}