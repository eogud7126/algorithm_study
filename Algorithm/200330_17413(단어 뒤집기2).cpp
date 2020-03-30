#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	getline(cin, S);
	stack<char> st;
	queue<char> q;
	bool stOrq = true;

	for (int i = 0;i <= S.size();i++) {
		if (stOrq) {
			st.push(S[i]);
			if (st.top() == '<') {
				st.pop();
				int stsize = st.size();
				if(!st.empty())
					for (int j = 0; j < stsize;j++) {
						cout << st.top();
						st.pop();
					}
				cout << "<";
				stOrq = false;
			}
			if (!st.empty()) {
				if (st.top() == ' ') {
					st.pop();
					int stsize = st.size();
					for (int j = 0; j < stsize;j++) {
						cout << st.top();
						st.pop();
					}
					cout << " ";
				}
				if (S[i] == '\0') {
					st.pop();
					int stsize = st.size();
					for (int j = 0; j < stsize;j++) {
						cout << st.top();
						st.pop();
					}
				}
			}
		}
		else {
			cout << S[i];
			if (S[i] == '>') stOrq = true;
		}
	}

	return 0;
}