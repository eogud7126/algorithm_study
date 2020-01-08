#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	long long N, M;
	vector<long long> A;
	vector<long long> B;
	int searchCount[MAX] = { 0, };
	bool flag1 = false, flag2 = false;
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		long long input;
		cin >> input;
		A.push_back(input);
	}
	sort(A.begin(), A.end());
	cin >> M;
	for (int k = 0;k < M;k++) {
		long long input;
		cin >> input;
		B.push_back(input);
		searchCount[k] = upper_bound(A.begin(), A.end(), B[k]) - lower_bound(A.begin(), A.end(), B[k]);
		cout << searchCount[k] << " ";
	}

	return 0;
}
