#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int alpha[256];

int cal(vector<string> &word, vector<char> &letters, vector<int> &nums) {
	int sum = 0;
	for (int i = 0;i < letters.size();i++) {
		alpha[letters[i]] = nums[i];
	}
	for (string w : word) {
		int now = 0;
		for (char l : w) {
			now = now * 10 + alpha[l];
		}
		sum += now;
	}
	return sum;
}

int main() {
	int N;
	cin >> N;
	vector<string> word(N);
	vector<char> letters;
	for (int i = 0;i < N;i++) {
		cin >> word[i];
		for (int j = 0;j < word[i].size();j++) {
			letters.push_back(word[i][j]);
		}
	}
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());
	int sizeofLetters = letters.size();
	vector<int> nums;
	for (int i = 9;i > 9 - sizeofLetters;i--) {
		nums.push_back(i);
	}
	int answer = 0;
	do {
		int now = cal(word, letters, nums);
		if (now > answer) {
			answer = now;
		}
	} while (prev_permutation(nums.begin(), nums.end()));
	cout << answer << endl;
	return 0;
}