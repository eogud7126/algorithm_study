#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	vector<int> A;
	vector<int> B;
	int N, M;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int data;
		cin >> data;
		A.push_back(data);
	}
	sort(A.begin(), A.end()); //�̺� Ž���� ���� ����
	cin >> M;

	for (int i = 0;i < M;i++) {
		int num;
		cin >> num;
		B.push_back(num);
	}

	int left;
	int right;
	int mid;

	for (int n = 0;n < M;n++) {
		left = 0;					//����
		right = A.size();			//������
		bool flag = false;
		
		while (left <= right && left<A.size() && right>=0) {
			mid = (left+right)/2;	//�߰���
			
			if (A[mid] < B[n]) {
				left = mid + 1;
			}
			else if (A[mid] > B[n]) {
				right = mid - 1;
			}
			if (A[mid] == B[n]) {
				cout << "1" << "\n";	//ã������
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "0" << "\n";

			
	}
	return 0;
}
