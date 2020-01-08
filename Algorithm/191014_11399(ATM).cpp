#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int N;
	int sum = 0;
	vector<int> P;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int t;
		cin >> t;
		P.push_back(t);
	}
	sort(P.begin(), P.end());

	for (int i = 1;i < P.size();i++)
		P[i] = P[i - 1] + P[i];
	for (int i = 0;i < P.size();i++)
		sum += P[i];
	cout << sum;
	return 0;
}
