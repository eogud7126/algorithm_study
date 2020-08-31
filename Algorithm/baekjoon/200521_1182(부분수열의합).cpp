#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

long long N, S;
vector<int> num;
long long cnt_S = 0;

void getSum(vector<int> v, int idx, long long ssum) {
	if (idx == N) {
		if (ssum == S) {
			cnt_S++;
		}
		return;
	}
	ssum =ssum+ v[idx];
	getSum(v, idx + 1, ssum);
	ssum =ssum- v[idx];
	getSum(v, idx + 1, ssum);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N>>S;
	for (int i = 0;i < N;i++) {
		int t;
		cin >> t;
		num.push_back(t);
	}
	int sum = 0;
	getSum(num, 0, sum);
	if (S == 0) cnt_S --;
	cout << cnt_S;
	return 0;
}


