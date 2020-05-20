#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;
int N;
int S[21][21];

//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>> a(n, vector<int>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> a[i][j];
//		}
//	}
//	vector<int> b(n);
//	for (int i = 0; i < n / 2; i++) {
//		b[i] = 1;
//	}
//	sort(b.begin(), b.end());
//	int ans = 2147483647;
//	do {
//		vector<int> first, second;
//		for (int i = 0; i < n; i++) {
//			if (b[i] == 0) {
//				first.push_back(i);
//			}
//			else {
//				second.push_back(i);
//			}
//		}
//		for (int i = 0;i < b.size() / 2;i++) {
//			cout << first[i] << " " << second[i] << endl;
//		}
//		cout << endl;
//		int one = 0;
//		int two = 0;
//		for (int i = 0; i < n / 2; i++) {
//			for (int j = 0; j < n / 2; j++) {
//				if (i == j) continue;
//				one += a[first[i]][first[j]];
//				two += a[second[i]][second[j]];
//			}
//		}
//		int diff = one - two;
//		if (diff < 0) diff = -diff;
//		if (ans > diff) ans = diff;
//	} while (next_permutation(b.begin(), b.end()));
//	cout << ans << '\n';
//	return 0;
//}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> S[i][j];
		}
	}
	vector<int> k(N);
	for (int i = 0;i < N / 2;i++) {
		k[i] = 1;
	}
	sort(k.begin(), k.end());
	do {
		vector<int> first, second;
		for (int i = 0;i < k.size();i++) {
			if (k[i] == 0)
				first.push_back(i);
			else
				second.push_back(i);
		}
		for (int i = 0;i < k.size()/2;i++) {
			cout << first[i]<<" "<<second[i]<<endl;
		}
		cout << endl;
	} while (next_permutation(k.begin(), k.end()));
	return 0;
}
