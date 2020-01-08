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
	long long K;
	int w;
	vector<int> weight;
	vector<int> sum_weight;
	cin >> K;
	for (int i = 0;i < K;i++) {
		cin >> w;
		weight.push_back(w);
	}
	sort(weight.begin(),weight.end());
	for (int i = 0;i < K;i++)
		sum_weight.push_back((K - i)*weight[i]);
	sort(sum_weight.begin(), sum_weight.end());

	cout << sum_weight[sum_weight.size() - 1];
	return 0;
}
