#include<iostream>
#include<vector>
#include<list>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		list<int> survivors;
		for (int i = 1;i <= N;i++) survivors.push_back(i);
		list<int>::iterator pointer = survivors.begin(); //ù��° ��ġ
		int n = survivors.size();
		while (n > 2) {
			pointer = survivors.erase(pointer); //pointer�� ���ŵ� ���� ���� ��ġ�� �̵�
			//���� ������ end�� ����Ų�ٸ� begin���� �ٲ���.(���� ��ȯ�� �ǵ���)
			if (pointer == survivors.end()) pointer = survivors.begin();
			n--;
			//���� ���ʸ� ���ϱ����� for��
			for (int i = 0;i < K - 1;i++) {
				pointer++;
				if (pointer == survivors.end()) pointer = survivors.begin();
			}
			
		}
		cout << survivors.front() << " " << survivors.back() << endl;
	}

	return 0;
}