#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int N;
string str;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> str;

	stack<char> comp;
	vector<int> tmp;
	int answer=0;

	int cntgwal = 0;
	for (int i = 0;i < N;i++) {
		if (comp.empty()) {
			if (str[i] == '(') {
				comp.push('(');
				cntgwal++;
			}
			else {
				cntgwal = 0;
			}
		}
		else {
			char toptmp = comp.top();
			if (toptmp == '(') {
				if (str[i] == ')') {
					cntgwal++;
					comp.pop();
					tmp.push_back(cntgwal);
				}
				else {
					comp.push('(');
					tmp.push_back(cntgwal);
					cntgwal = 1;
				}
			}
		}
		cout << cntgwal << endl;
		if (i == N - 1) {
			tmp.push_back(cntgwal);
		}
	}
	for (int i = 0;i < tmp.size();i++) {
		cout << tmp[i] << endl;
	}
	//cout << answer;
	return 0;
}
