#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<int> trees(N);
	for (int i = 0;i < N;i++) cin >> trees[i];

	sort(trees.begin(), trees.end());
	//이분탐색 시작
	long long left = 0, right = trees[trees.size() - 1];
	long long mid = (int)((left + right) / 2) ;
	long long summid = 0, answer = 0;
	while (left<=right) {
		summid = 0;
		for (int i = 0;i < N;i++) {
			if (trees[i] > mid) {
				summid = summid + trees[i] - mid;
			}
		}
		if (summid >= M) {
			if(answer<mid)
				answer = mid;
			left = mid + 1;
		}
		if (summid < M) right = mid - 1;
		mid = (left + right) / 2;

	}
	cout << mid << "\n";
	return 0;
}