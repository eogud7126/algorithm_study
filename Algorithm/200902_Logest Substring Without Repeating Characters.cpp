#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<functional>
#include<sstream>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

using namespace std;

int NUM[27] = { 0, };

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int answer =0;
		int j = 0;
		while (j < s.size()) {
			int a = 0;
			memset(NUM, 0, sizeof(NUM));
			for (int i = j;i < s.size();i++) {
				if (NUM[s[i] - 97] == 0) {
					NUM[s[i] - 97]++;
					a++;
				}
				else break;
			}
			if (answer < a)
				answer = a;
			j++;
		}
		return answer;
	}
}; 

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;

	return 0;
}