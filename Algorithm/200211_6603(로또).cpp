#include<iostream>
#include<vector>

using namespace std;

int inputarr[13];
int lotto[6];
int n;

void printLotto(int idx1, int idx2) {
	if (idx2 == 6) {
		for (int i = 0;i < 6;i++) cout << lotto[i] << " ";
		cout << "\n";
	}
	for (int i = idx1;i < n;i++) {
		lotto[idx2] = inputarr[i];
		printLotto(i + 1, idx2 + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	while (1) {
		
		cin >> n;
		if (n == 0) break;
		for (int i = 0;i < n;i++) {
			cin >> inputarr[i];
		}
		printLotto(0, 0);
		cout << "\n";
	}
	return 0;
}