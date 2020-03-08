
#include<iostream>

using namespace std;


long long way(int r, int c) {
	long long a = 1;
	for (int i = r + c;i > r;i--) {
		a *= i;
	}
	for (int i = 1;i <= c;i++)
		a /= i;
	return a;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int R, C, necc;
	cin >> R >> C >> necc;
	int idx = 0;
	int nr;
	int nc;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			idx++;
			if (idx == necc) {
				nr = i;
				nc = j;
				break;
			}
		}
	}
	
	int r = R - 1;
	int c = C - 1;


	if (necc != 0) {
		long long way1 = way(nr, nc);
		long long way2 = way(r - nr, c - nc);
		//cout << nr << " " << nc << endl;
		cout << way1 * way2 << "\n";
	}
	else
		cout << way(r, c)<<"\n";
	return 0;
}