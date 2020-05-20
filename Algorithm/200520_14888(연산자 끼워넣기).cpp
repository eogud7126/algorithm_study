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
vector<int> nums;
vector<int> ops;
int inp_op[4];

int getAnswer(vector<int> op) {
	long long ret=nums[0];
	for (int i = 0;i < op.size();i++) {
		if (op[i] == 0) {
			ret += nums[i + 1];
		}
		else if (op[i] == 1) {
			ret -= nums[i + 1];
		}
		else if (op[i] == 2) {
			ret *= nums[i + 1];
		}
		else {
			ret /= nums[i + 1];
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		nums.push_back(k);
	}
	for (int i = 0;i < 4;i++) {
		cin >> inp_op[i];
	}
	for (int i = 0;i < n-1;i++) {
		for (int j = 0;j < 4;j++) {
			if (inp_op[j] > 0) {
				inp_op[j]--;
				ops.push_back(j);
			}
		}
	}
	sort(ops.begin(), ops.end());
	long long answerMax = -100000000;
	long long answerMin = 1000000000;
	do {
		int tmp = getAnswer(ops);
		if (answerMax < tmp) {
			answerMax = tmp;
		}
		if (answerMin > tmp) {
			answerMin = tmp;
		}
	} while (next_permutation(ops.begin(), ops.end()));
	cout << answerMax << "\n" << answerMin;
	return 0;
}
