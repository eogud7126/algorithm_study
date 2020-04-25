#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	vector<char> cal;
	queue<int> numbers;
	queue<char> plusminus;
	string str="";
	queue<int> q_plus;
	queue<int> q_minus;

	cin >> str;
	for (int i = 0;i < str.size();i++)
		cal.push_back(str[i]);
	string sum = "";
	for (int i = 0;i < cal.size();i++) {
		if (cal[i] != '+' && cal[i] != '-') {
			sum += cal[i];
		}
		else {
			plusminus.push(cal[i]);
			numbers.push(stoi(sum));
			sum = "";
		}
	}
	numbers.push(stoi(sum));
	q_plus.push(numbers.front());
	numbers.pop();
	char ex_pm = '+';
	int pmsize = plusminus.size();
	/*for (int i = 0;i < pmsize ;i++) {
		cout << plusminus.front();
		plusminus.pop();
	}*/

	while (!plusminus.empty()) {
		if (plusminus.front() == '+') {
			if (ex_pm == '-') {
				q_minus.push(numbers.front());
			}
			else {
				q_plus.push(numbers.front());
			}
		}
		else { //-ÀÏ¶§ 
			q_minus.push(numbers.front());
			ex_pm = '-';
		}
		plusminus.pop();
		numbers.pop();
	}
	int sumA = 0; int Asize = q_plus.size();
	int sumB = 0; int Bsize = q_minus.size();
	for (int i = 0;i < Asize;i++) {
		sumA += q_plus.front();
		q_plus.pop();
	}
	for (int i = 0;i < Bsize;i++) {
		sumB += q_minus.front();
		q_minus.pop();
	}
	cout << sumA - sumB;
	return 0;
}
