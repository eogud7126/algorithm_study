#include<iostream>
#include<string>
#include<cstdio>
#include<queue>

using namespace std;
bool visit[200001] = { false, };
long long cnt[200001] = { 0, };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	queue<long long> q;
	long long N, K;
	cin >> N >> K;

	q.push(N);
	visit[N] = true;
	while (!q.empty()) {
		long long xp1 = q.front() + 1;
		long long xm1 = q.front() - 1;
		long long twice = q.front() * 2;
		long long qfront = q.front();
		q.pop();

		if (visit[xp1] == false && xp1<=100000) {
			q.push(xp1);
			visit[xp1] = true;
			cnt[xp1] = cnt[qfront] + 1;
		}
		if (xm1>=0 && visit[xm1] == false) {
			q.push(xm1);
			visit[xm1] = true;
			cnt[xm1] = cnt[qfront] + 1;
		}
		if (visit[twice] == false && twice<=100000) {
				q.push(twice);
				visit[twice] = true;
				cnt[twice] = cnt[qfront] + 1;			
		}
		//cout << q.front() <<"\t"<<cnt[q.front()]<< endl;
		if (xp1 == K || xm1 == K || twice == K) {
			cout << cnt[K] << "\n";
			break;
		}

	}


	return 0;
}
