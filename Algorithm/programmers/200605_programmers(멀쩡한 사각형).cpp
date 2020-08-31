#include<algorithm>
#include<iostream>

using namespace std;

int getGCD(int a, int b) {
	int mx = max(a, b);
	int mn = min(a, b);
	while (mx%mn != 0) {
		int tmp = mx % mn;
		mx = mn;
		mn = tmp;
	}
	return mn;
}
long long solution(int w, int h) {
	long long answer = (long long)w*(long long)h;
	int gcd = getGCD(w, h);
	int wmin = w / gcd;
	int hmin = h / gcd;
	int tmp = wmin + hmin - 1;
	long long minus = tmp * gcd;
	answer -= minus;
	return answer;
}