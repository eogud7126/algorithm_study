#include <iostream>
#include<Windows.h>
using namespace std;

int k;
int s[14]; // ����
int l[14]; // �ζ�

void dfs(int node, int depth) {
	cout << "���: " << node-1 << " ����: " << depth-1 << endl;

	//if (depth == 7) { // ���� ���̱��� Ž���� �ߴٸ� �ζ� ��ȣ ���
	//	for (int i = 1; i <= 6; ++i) {
	//		cout << l[i] << " ";
	//	}
	//	cout << "\n";
	//	return;
	//}

	for (int i = node; i <= k; ++i) { // ��� ��带 �ϳ��� ������ DFS�� �����Ѵ�.
		l[depth] = s[i];
		dfs(i + 1, depth + 1);
	}

}

int main() {
	while (cin >> k && k) {
		for (int i = 1; i <= k; ++i)
			cin >> s[i];

		dfs(1, 1);
		cout << "\n";
	}

	return 0;
}