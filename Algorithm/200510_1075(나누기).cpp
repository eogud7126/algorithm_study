#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

string N;
int F;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> F;
	int zerozero = stoi(N.substr(0, N.size() - 2)+"00");
	string answer;
	for (int i = 0;i < 99;i++) {
		if ((zerozero + i) % F == 0) {
			answer = to_string(i);
			break;
		}
	}
	if (answer.size() == 1)
		answer = "0" + answer;
	cout << answer;
	return 0;
}
