#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

bool check(vector<int> &nums, vector<char> &boodngho) {
	for (int i = 0;i < boodngho.size();i++) {
		if (boodngho[i] == '<' && nums[i] > nums[i + 1]) {
			return false;
		}
		if (boodngho[i] == '>' && nums[i] < nums[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int k;
	cin >> k;
	vector<char> boodngho(k);
	for (int i = 0;i < k;i++) {
		cin >> boodngho[i];
	}
	vector<int> small(k + 1);
	vector<int> big(k + 1);
	for (int i = 0;i < k+1;i++) {
		small[i] = i;
		big[i] = 9 - i;
	}
	do {
		if (check(small, boodngho)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));
	do {
		if (check(big, boodngho)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));


	for (int i = 0;i < big.size();i++) {
		cout << big[i];
	}
	cout << '\n';
	for (int i = 0;i < small.size();i++) {
		cout << small[i];
	}
	return 0;
}