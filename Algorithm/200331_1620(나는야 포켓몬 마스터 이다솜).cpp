#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

map<string,int> pokemon;
vector<string> pokemon2;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T;
	cin >> N >> T;

	for (int i = 1;i <= N;i++) {
		string name;
		cin >> name;
		pokemon.insert(make_pair(name,i));
		pokemon2.push_back(name);
	}
	for (int i = 0;i < T;i++) {
		string quiz;
		cin >> quiz;
		if ('A' <= quiz[0] && quiz[0] <= 'Z') {
			/*map<string, int>::iterator iter;
			iter = pokemon.find(quiz);
			if (iter != pokemon.end()) cout << iter->second << "\n";*/
			cout << pokemon[quiz] << endl;
		}
		else
			cout << pokemon2[stoi(quiz)-1] << "\n";
	}
	return 0;
}