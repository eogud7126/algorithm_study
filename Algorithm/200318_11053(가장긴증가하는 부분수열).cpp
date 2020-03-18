#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 1001

long long D[MAX];
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int P[MAX];

	for (int i = 1;i <= n;i++) {
		cin >> P[i];
	}
	fill_n(D, n + 1, 1);
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j < i;j++) {
			if (P[j] < P[i]) {
				if(D[i]<D[j]+1)
					D[i] = D[j] + 1;
			}
		}
	}
	cout << *max_element(D,D+n+1) << "\n";
	return 0;
}