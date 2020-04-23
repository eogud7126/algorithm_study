#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

int N, K;
vector<int> sensors;
vector<int> gap;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		int inp;
		cin >> inp;
		sensors.push_back(inp);
	}
	if (sensors.size() == 1) {
		cout << 0 << endl;
		return 0;
	}
	sort(sensors.begin(), sensors.end());
	for (int i = 1;i < sensors.size();i++) {
		int sub;
		sub = sensors[i] - sensors[i - 1];
		gap.push_back(sub);
	}
	sort(gap.begin(), gap.end());
	int sum = 0;
	for (int i = 0;i < gap.size() - K + 1;i++) {
		sum += gap[i];
	}
	cout << sum << endl;
	return 0;
}
