#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;
int n;
vector<int> num;
bool visited[2000001] = { false, };

void getAnswer(int idx, int sum) {
	if (idx == n) {
		visited[sum] = true;
		return;
	}
	sum += num[idx];
	getAnswer(idx + 1, sum);
	sum -= num[idx];
	getAnswer(idx + 1, sum);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	visited[0] = true;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		num.push_back(t);
	}
	getAnswer(0, 0);
	//가장작은것..
	int ii = 0;
	while (1) {
		if (!visited[ii]) {
			cout << ii << "\n";
			break;
		}
		ii++;
	}
	return 0;
}


