#include<iostream>
#include<vector>
#include<algorithm>
/*
�Է�: ũ�Ⱑ 4�� �迭
+,*,()�� ����ؼ� ���� ū �� �����
*/
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	vector<int> compareNum;

	int input[4];
	int a, b, c, d;
	for (int i = 0;i < 4;i++) {
		cin >> input[i];
	}
	a = input[0]; b = input[1]; c = input[2];d = input[3];
	
	compareNum.push_back(a*b*c*d);
	compareNum.push_back((a+b)*c*d);
	compareNum.push_back(a*(b+c)*d);
	compareNum.push_back(a*b*(c+d));
	compareNum.push_back((a+b+c)*d);
	compareNum.push_back((a+b)*(c+d));
	compareNum.push_back(a*(b+c+d));
	compareNum.push_back(a+b+c+d);

	cout << *max_element(compareNum.begin(), compareNum.end())<<endl;
	return 0;
}