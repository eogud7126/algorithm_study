//Ʋ�Ƚ��ϴ�. �ٽ� �ѹ� Ǯ�����;
#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

vector<pair<int, bool>> MAP;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1;i <= 20;i++)
		MAP.push_back(make_pair(i * 2, false));
	MAP[21] = make_pair(13, false);
	MAP[22] = make_pair(16, false);
	MAP[23] = make_pair(19, false);
	MAP[24] = make_pair(25, false); //�߰�
	MAP[25] = make_pair(22, false);
	MAP[26] = make_pair(24, false);
	MAP[27] = make_pair(28, false);
	MAP[28] = make_pair(27, false);
	MAP[29] = make_pair(26, false);
	MAP[30] = make_pair(30, false);
	MAP[31] = make_pair(35, false);

	vector<int> dice(10);
	for (int i = 0;i < 10;i++) {
		int inp;
		cin >> inp;
		dice[i] = inp;
	}
	int answer = 0;
	int imhere;
	int dicesum = 0;
	bool flag1, flag2, flag3;
	for (int i = 0;i < 10;i++) {
		dicesum += dice[i];
		//�� �ڸ��� ���� �ִ��� Ȯ��..
		if (!MAP[dicesum].second) {
			//������ üũ
			if (dicesum == 5) {
				flag1 = true;
			}
			else if (dicesum == 10) {
				flag2 = true;
			}
			else if (dicesum == 15) {
				flag3 = true;
			}
			else {

			}
		}
		//���� �ִٸ�?
		else {

		}
	}

	return 0;
}
