#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
/*
�Է�: ũ�Ⱑ 4�� �迭
+,*,()�� ����ؼ� ���� ū �� �����
*/
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string n;
	int k, cnt = 1;
	cin >> n >> k;
	string nn = n;
	while (1) {
		cnt++;
		nn.append(n);
		if (stoll(nn) % k == 0)
			break;
	}
	
	cout << cnt << endl;

	return 0;
}