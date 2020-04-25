#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

bool visited[101] = { false, };
int familynum;
int p, q;
int n;
vector<int> relation[101];
queue<pair<int,int>> bfsQ;

int bfs(int m) {
	visited[m] = true;
	bfsQ.push(make_pair(m,0));

	while (!bfsQ.empty()) {
		int qfront = bfsQ.front().first;
		int chonsu = bfsQ.front().second;
		chonsu++;
		bfsQ.pop();
		for (int i = 0;i < relation[qfront].size();i++) {
			if (!visited[relation[qfront][i]]) {
				
				bfsQ.push(make_pair(relation[qfront][i], chonsu));
				visited[relation[qfront][i]] = true;
				//cout<<i<<" "<< relation[qfront][i] << " " << chonsu<<  endl;
				if (relation[qfront][i] == q) return chonsu;
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> familynum >> p >> q >> n;
	for (int i = 0;i < n;i++) {
		int u, v;
		cin >> u >> v;
		relation[u].push_back(v);
		relation[v].push_back(u);
	}
	cout << bfs(p) << endl;



	return 0;
}