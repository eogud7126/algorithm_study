
#include<iostream>
/*
격자에서 오른쪽, 아래로밖에 못갈때 
R,C까지 가는 경우의 수
*/
using namespace std;

int factorial(int n) {
	if (n == 1)
		return 1;
	else 
		return n * factorial(n - 1);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int R, C;
	cin >> R >> C;
	int r = R - 1;
	int c = C - 1;

	cout << factorial(r+c)/(factorial(r)*factorial(c))<<endl;
	return 0;
}