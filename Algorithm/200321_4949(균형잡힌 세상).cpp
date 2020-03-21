#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

#define MAX 100001
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		bool isno = true;
		getline(cin, s);
		stack<char> st;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			if (s[i] == ')') {
				if (!st.empty()&&st.top() == '(') {
					st.pop();
				}
				else {
					cout << "no\n";
					isno = false;
					break;
				}
			}
			if (s[i] == ']') {
				if (!st.empty()&&st.top() == '[') {
					st.pop();
				}
				else {
					cout << "no\n";
					isno = false;
					break;
				}
			}
		}
		
		if (s == ".") break;
		if (st.empty() && isno) cout << "yes\n";
		if (!st.empty() && isno) cout << "no\n";
	}
	return 0;
}