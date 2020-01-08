#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
long long A[11] = { 0, };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int N;
	long long K;
	long long rest;
	int sub_cnt = 0;
	int cnt = 0;
	cin >> N >> K;
	for (int i = 0;i < N;i++) 
		cin >> A[i];
	for (int i = N - 1;i >= 0;i--) {
		if (K < A[i]) continue;
		else {
			cnt = cnt + (int)(K / A[i]);
			rest = K % A[i];
			K = rest;
		}
		if (K == 0) break;
	}
	cout << cnt;
	return 0;
}
