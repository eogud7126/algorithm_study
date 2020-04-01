#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> st;
	st.push(s[0]);
	for (int i = 1;i < s.size();i++) {
		if (!st.empty() && st.top() == s[i]) st.pop();
		else st.push(s[i]);
	}
	if (st.empty()) answer = 1;
	return answer;
}



