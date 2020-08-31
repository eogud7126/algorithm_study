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
vector<string> word;
vector<char> letters;
int alpha[256];

int getAnswer(vector<int> n) {
	int ret = 0;
	for (int i = 0;i < word.size();i++) {
		int tmp = 0;
		for (int j = 0;j < word[i].size();j++) {
			tmp = tmp * 10 + alpha[word[i][j]];
		}
		ret += tmp;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		string tmp;
		cin >> tmp;
		word.push_back(tmp);
	}

	for (int i = 0;i < word.size();i++) {
		for (int j = 0;j < word[i].size();j++) {
			letters.push_back(word[i][j]);
		}
	}
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());
	vector<int> num;
	for (int i = 0;i < letters.size();i++) {
		num.push_back(9 - i);
	}
	//sort(num.begin(), num.end());
	int answer = 0;
	do {
		for (int i = 0;i < letters.size();i++) {
			alpha[letters[i]] = num[i];
		}
		int tmp = getAnswer(num);
		if (answer < tmp)
			answer = tmp;
	} while (prev_permutation(num.begin(), num.end()));
	cout << answer;
	return 0;
}
