#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;
int k;
vector<int> lotto;

void selectNum(vector<int> &v, int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0;i < 6;i++)
			cout << lotto[i] << " ";
		cout << "\n";
		return;
	}
	if (idx == v.size()) return;
	lotto.push_back(v[idx]);
	selectNum(v, idx + 1, cnt + 1);
	lotto.pop_back();
	selectNum(v, idx + 1, cnt);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		cin >> k;
		if (!k) break;
		vector<int> num(k);
		for (int i = 0;i < k;i++) {
			cin >> num[i];
		}
		selectNum(num, 0,0);
		cout << "\n";
	}
	return 0;
}
