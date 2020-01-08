#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	int N;
	cin >> N;
	for (int i = 0; i < N;i++) {
		int num;
		cin >> num;
		

		if (num != 0) {
			pq.push(make_pair(abs(num), num));
		}
		else {//0입력
			if (pq.empty()) { //비어있으면!
				cout << 0 << "\n";
			}
			else {
				cout <<pq.top().second << "\n";
				pq.pop();
			}
		}
	}
	return 0;
}
