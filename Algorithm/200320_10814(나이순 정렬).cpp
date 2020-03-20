#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define MAX 100001
using namespace std;
int n;

struct user {
	int when;
	int age;
	string name;
};

bool cmp(const user &u1 , const user &u2) {
	if (u1.age < u2.age) return true;
	else if (u1.age == u2.age) {
		if (u1.when < u2.when) return true;
		else return false;
	}
	else return false;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<user> users(n);
	for (int i = 0;i < n;i++) {
		cin >> users[i].age >> users[i].name;
		users[i].when = i;
	}
	sort(users.begin(), users.end(), cmp);
	for (int i = 0;i < users.size();i++)
		cout << users[i].age << " " << users[i].name << "\n";
	return 0;
}