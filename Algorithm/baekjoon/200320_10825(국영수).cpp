#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define MAX 100001
using namespace std;
int N;

struct Score {
	int eng, kor, math;
	string name;
};
bool cmp(const Score &s1, const Score &s2) {
	if (s1.kor > s2.kor) return true;
	else if (s1.kor == s2.kor) {
		if (s1.eng < s2.eng) return true;
		else if (s1.eng == s2.eng) {
			if (s1.math > s2.math) return true;
			else if (s1.math == s2.math) {
				if (s1.name < s2.name) return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
	return false;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<Score> students(N);

	for (int i = 0;i < N;i++) 
		cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
	sort(students.begin(), students.end(), cmp);
	
	for (int i = 0;i < N;i++)
		cout << students[i].name << "\n";
	return 0;
}