#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;

int getGCD(int m, int n) {
	int big = m;
	int small = n;
	if (m < n) {
		big = n;
		small = m;
	}
	while (small != 0) {
		int res;
		res = big % small;
		big = small;
		small = res;
	}
	return big;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	
	vector<int> num;
	istringstream ss(s);
	string stringBuffer;
	while (getline(ss, stringBuffer, ':'))
		num.push_back(stoi(stringBuffer));
	int gcd = getGCD(num[0], num[1]);
	cout << num[0] / gcd << ":" << num[1] / gcd << "\n";
	return 0;
}