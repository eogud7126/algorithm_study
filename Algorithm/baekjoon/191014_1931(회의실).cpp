#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
struct confluence {
	long long x;
	long long y;
};

bool cmp(const confluence &u, const confluence & v) {
	if (u.y < v.y) return true;
	else if (u.y == v.y) return u.x < v.x;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	long long N;
	long long cnt=0;
	cin >> N;
	vector <confluence> a;
	queue<confluence> tempq;
	queue<confluence> q;
	for (int i = 0; i < N;i++) {
		confluence c;
		cin >> c.x >> c.y;
		a.push_back(c);
	}
	sort(a.begin(), a.end(),cmp); //끝나는 시간 작은것대로 정렬
	for (int i = 0;i < a.size();i++) tempq.push(a[i]);
	q.push(tempq.front());
	tempq.pop();
	while (!q.empty()) {
		long long sizeofq = tempq.size();
		for (int i = 0;i < sizeofq ; i++) {
			if (q.front().y <= tempq.front().x) {
				q.push(tempq.front());
				tempq.pop();
				break;
			}
			else tempq.pop();
		}
		q.pop();
		cnt++;
	}
	cout << cnt;
	return 0;
}
