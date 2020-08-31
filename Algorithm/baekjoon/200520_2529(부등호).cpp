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
vector<char> boodng(9);

bool isCorrect(vector<int> num) {
	for (int i = 1;i < num.size();i++) {
		if (boodng[i - 1] == '<') {
			if (num[i - 1] > num[i]) return false;
		}
		else {
			if (num[i - 1] < num[i]) return false;
		}
	}
	return true;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	for (int i = 0;i < k;i++) {
		cin >> boodng[i];
	}
	vector<int> maxN;
	vector<int> minN;
	int mx = 9;
	int mn = 0;
	for (int i = 0;i <= k;i++) {
		maxN.push_back(mx--);
		minN.push_back(mn++);
	}
	do {
		if (isCorrect(minN)) {
			break;
		}
	} while (next_permutation(minN.begin(), minN.end()));
	do {
		if (isCorrect(maxN)) {
			break;
		}
	} while (prev_permutation(maxN.begin(), maxN.end()));
	for (int i = 0;i < maxN.size();i++)
		cout << maxN[i];
	cout << "\n";
	for (int i = 0;i < minN.size();i++)
		cout << minN[i];
	return 0;
}
