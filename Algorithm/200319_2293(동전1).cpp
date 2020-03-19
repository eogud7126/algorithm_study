#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;
#define MAX 10001
int N, K;
long long D[MAX];
int COIN[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1;i <= N;i++)
		cin >> COIN[i];
	D[0] = 1;
	//N가지 K원 만들기
	for (int i = 1;i <= N;i++) {
		for (int j = 1; j<=K;j++) {
			if(j-COIN[i]>=0)
				D[j] += D[j - COIN[i]];

		}
	}
	cout << D[K] << "\n";
	return 0;
}


