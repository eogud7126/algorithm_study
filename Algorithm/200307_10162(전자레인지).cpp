#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin >> T;
	int A = 300, B = 60, C = 10;
	int Acnt = 0, Bcnt = 0, Ccnt = 0;


	if (T >= A) {
		Acnt = T / A;
		T %= A;
	}
	if (T >= B) {
		Bcnt = T / B;
		T %= B;
	}
	if (T >= C) {
		Ccnt = T / C;
		T %= C;
	}

	if (T == 0) cout << Acnt << " " << Bcnt << " " << Ccnt << "\n";
	else cout << "-1" << "\n";

	return 0;
}