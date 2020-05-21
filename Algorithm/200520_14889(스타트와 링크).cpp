#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;
int N;
int S[21][21];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> S[i][j];
		}
	}
	vector<int> nums(N);
	for (int i = 0;i < N/2;i++) {
		nums[i] = 1;
	}
	sort(nums.begin(), nums.end());
	int answerMin = 98765432;
	do {
		vector<int> first, second;
		int firstSum = 0, secondSum = 0;
		for (int i = 0;i < N;i++) {
			if (nums[i] == 1)
				first.push_back(i);
			else
				second.push_back(i);
		}
		for (int i = 0;i < N / 2;i++) {
			for (int j = i + 1;j < N / 2;j++) {
				firstSum += (S[first[i]][first[j]] + S[first[j]][first[i]]);
				secondSum += (S[second[i]][second[j]] + S[second[j]][second[i]]);
			}
		}
		
		int tmp = abs(firstSum - secondSum);
		if (answerMin > tmp) {
			answerMin = tmp;
		}
	} while (next_permutation(nums.begin(), nums.end()));
	cout << answerMin << "\n";
	return 0;
}
