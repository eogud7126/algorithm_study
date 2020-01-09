#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string brackets;
		bool isvalid = true;
		cin >> brackets;
		stack<char> bracket_stack;
		if (brackets[0] == ')' || brackets[0] == '}' || brackets[0] == ']') {
			cout << "NO" << endl;
			continue;
		}
		else {
			bracket_stack.push(brackets[0]);
		}
		for (int i = 1;i < brackets.size();i++) {
			if ((brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']') && !bracket_stack.empty()) {
				switch (bracket_stack.top()) {
				case '(':
					if (brackets[i] == ')') bracket_stack.pop();
					else {
						cout << "NO" << endl;
						isvalid = false;
					}
					break;
				case '{':
					if (brackets[i] == '}') bracket_stack.pop();
					else {
						cout << "NO" << endl;
						isvalid = false;
					}
					break;
				case '[':
					if (brackets[i] == ']') bracket_stack.pop();
					else {
						cout << "NO" << endl;
						isvalid = false;
					}
					break;
				default: 
					cout << "NO";
					isvalid = false;
					break;
				}
				if (!isvalid) break;
			}
			else {
				bracket_stack.push(brackets[i]);
			}
		}
		if (isvalid) {
			if(bracket_stack.empty())
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		
	}
	return 0;
}

/*
const string opening("({["), closing(")}]");
이렇게 한 후 
if (opening.find(brackets[i]) != -1) //열린 괄호라면...
*/