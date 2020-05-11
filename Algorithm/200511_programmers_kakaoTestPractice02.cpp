#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

char op[3] = { '+','-','*' };
int p[3] = { 0,1,2 };
vector<int> num;
vector<int> oper;

long long calc(long long X, long long Y, int op) {
	if (!op) return X + Y;
	else if (op & 1) return X - Y;
	else return X * Y;
}
long long getAns() {
	vector<int> num2;
	vector<int> num3;
	vector<int> oper2;
	vector<int> oper3;
	num2.push_back(num[0]);
	for (int i = 0;i < oper.size();i++) {
		if (oper[i] == p[0]) {
			num2[num2.size() - 1] = calc(num2[num2.size() - 1], num[i + 1], oper[i]);
		}
		else {
			num2.push_back(num[i + 1]);
			oper2.push_back(oper[i]);
		}
	}
	num3.push_back(num2[0]);
	for (int i = 0;i < oper2.size();i++) {
		if (oper2[i] == p[1]) {
			num3[num3.size() - 1] = calc(num3[num3.size() - 1], num2[i + 1], oper2[i]);
		}
		else {
			num3.push_back(num2[i + 1]);
			oper3.push_back(oper[i]);
		}
	}
	long long last = num3[0];
	for (int i = 1;i < num3.size();i++) {
		last = calc(last, num3[i], p[2]);
	}
	return last;
}
long long solution(string a) {
	long long answer=0;
	int number = 0;
	for (int i = 0;i < a.size();i++) {
		int isOp = 0;
		for (int o = 0;o < 3;o++) {
			if (a[i] == op[o]) {
				isOp = o + 1;
			}
		}
		if (!isOp) {
			number = number * 10 + (a[i] - '0');
		}
		else {
			num.push_back(number);
			oper.push_back(isOp - 1);
			number = 0;
		}
	}
	num.push_back(number);
	for (int i = 0;i < 6;i++) {
		long long A = getAns();
		if (answer < abs(A)) {
			answer = abs(A);
		}
		next_permutation(p, p + 3);
	}

	return answer;
}
int main() {

	cout << solution("100-200*300-500+20") << endl;

	return 0;
}