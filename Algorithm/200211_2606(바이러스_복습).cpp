#include<iostream>
#include<vector>

using namespace std;

bool visit[101] = { false, };
vector<int> A[101];
int count_virus = -1;

void dfs(int n) {
	if (!visit[n]) {
		visit[n] = true;
		count_virus++;
		for (int i = 0;i < A[n].size();i++) {
			dfs(A[n][i]);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int com, pairs;
	
	cin >> com >> pairs;
	for (int i = 0;i < pairs;i++) {
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	dfs(1);

	cout << count_virus << endl;

}