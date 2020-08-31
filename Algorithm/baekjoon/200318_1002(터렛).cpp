#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
struct turret {
	int x;
	int y;
	int r;
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	turret T1, T2;
	int T;
	cin >> T;
	while (T--) {
		cin >> T1.x >> T1.y >> T1.r;
		cin >> T2.x >> T2.y >> T2.r;
		double distance = sqrt(pow(T1.x - T2.x, 2) + pow(T1.y - T2.y,2));
	
		if (T1.x == T2.x && T1.y == T2.y && T1.r == T2.r) {
			cout << -1 << "\n";
			continue;
		}
		int minR = T1.r < T2.r ? T1.r : T2.r;
		int maxR = T1.r > T2.r ? T1.r : T2.r;
		if (distance == T1.r + T2.r || distance + minR == maxR) {
			cout << 1 << "\n";
			continue;
		}
		if (distance > T1.r + T2.r || maxR > minR + distance) {
			cout << 0 << "\n";
			continue;
		}
		if (distance < T1.r + T2.r) cout << 2 << "\n";
	}
	return 0;
}